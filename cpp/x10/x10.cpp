#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include "x10.h"
#include "gpio.h"

using namespace std;


// Half copy pasta currently from https://github.com/tigoe/x10/blob/master/x10.cpp

x10::x10(GPIO* zero, GPIO* tx) : zeroPin(zero), txPin(tx) {
  zeroPin->input();
  txPin->output();
  txPin->setLow();
}

x10::~x10() {}

int x10::send(char houseCode, char numberCode, int times) {
  for(int i=1; i<=times; i++) { // Send everything twice because once isn't enough
    sendStartCmd();
    sendHouse(houseCode);
    sendKey(numberCode);

    if((numberCode != BRIGHT) && (numberCode != DIM)) {
      waitForZeroCross(6);
    }
  }
  return 0;
}

// So this all can be cleaned up quite a bit...
int x10::sendStartCmd(void) {
  char thisBit;
  for(int i=0; i<=3; i++) {
    waitForZeroCross(1);
    thisBit = (startCode << i) & 0b1000;

    for(int phase=0; phase<=2; phase++) {
      write(thisBit);
      usleep(TIME);
      write(0);
      usleep(TIME);
    }
  }
  return 0;
}

int x10::sendHouse(char house) {
  char thisBit;
  for(int i=0; i<=3; i++) {
    waitForZeroCross(1);
    thisBit = (house << i) & 0b1000;

    for(int phase=0; phase<=2; phase++) {
      write(thisBit);
      usleep(TIME);
      write(0);
      usleep(TIME);
    }

    waitForZeroCross(1);
    for(int phase=0; phase<=2; phase++) {
      write(!thisBit);
      usleep(TIME);
      write(0);
      usleep(TIME);
    }
  }
  return 0;
}

int x10::sendKey(char key) {
  char thisBit;
  for(int i=0; i<=4; i++) {
    waitForZeroCross(1);
    thisBit = (key << i) & 0b10000;

    for(int phase=0; phase<=2; phase++) {
      write(thisBit);
      usleep(TIME);
      write(0);
      usleep(TIME);
    }

    waitForZeroCross(1);
    for(int phase=0; phase<=2; phase++) {
      write(!thisBit);
      usleep(TIME);
      write(0);
      usleep(TIME);
    }
  }
  return 0;
}
// End clean up needed area

int x10::waitForZeroCross(int howMany) {
  for (int i=0; i<howMany; i++) {
    cout << "Waiting for change" << endl;
    if(zeroPin->getValue()) {
      while(zeroPin->getValue()) {}
    } else {
      while(!zeroPin->getValue()) {}
    }
  }
  return 0;
}

int x10::write(char val) {
  if((bool)val) {
    txPin->setHigh();
  } else {
    txPin->setLow();
  }
  return 0;
}
