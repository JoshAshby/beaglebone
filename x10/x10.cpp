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
}

x10::~x10() {}

int x10::send(char houseCode, char numberCode) {
  sendStartCmd();
  sendCmd(houseCode, 4);
  sendCmd(numberCode, 5);

  if((numberCode != BRIGHT) && (numberCode != DIM)) {
    waitForZeroCross(6);
  }
}

int x10::sendStartCmd(void) {
  char thisBit;
  for(int i=1; i<=3; i++) {
    waitForZeroCross(1);
    thisBit = (startCode << i) & 0b1000;
    cout << thisBit; // This is blank :/

    for(int phase=0; phase<=2; phase++) {
      write(thisBit);
      usleep(TIME);
      write(0);
      usleep(TIME);
    }
    cout << endl;
  }
}

int x10::sendCmd(char cmd, int numBits) {
  char thisBit;
  for(int i=1; i<=numBits; i++) {
    waitForZeroCross(1);
    thisBit = cmd & (1 << (numBits - i));

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

int x10::waitForZeroCross(int howMany) {
  for (int i=0; i<howMany; i++) {
    if(zeroPin->getValue()) {
      while(zeroPin->getValue()) {}
    } else {
      while(!zeroPin->getValue()) {}
    }
  }
  return 0;
}

int x10::write(int val) {
  if(val) {
    txPin->setHigh();
  } else {
    txPin->setLow();
  }
}
