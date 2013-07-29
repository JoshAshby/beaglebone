#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "gpio.h"

using namespace std;


int main() {
  cout << "Hi beagle!" << endl;

  GPIO led(1, 6);
  led.exportPin();
  led.output();

  GPIO btn(1, 7);
  btn.exportPin();
  btn.input();

  for(int i=0; i<=9; i++) {
    sleep(5);
    led.setHigh();
    sleep(5);
    led.setLow();
  }

  cout << "Press the button!" << endl;

  bool val = false;
  while(!val) {
    val = btn.getValue();
  }

  cout << "Button!" << endl;

  led.unexportPin();
  btn.unexportPin();
  return 0;
}
