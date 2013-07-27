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
  led.input();

  for(int i=0; i<=9; i++) {
    sleep(5);
    led.setHigh();
    sleep(5);
    led.setLow();
  }

  led.unexportPin();
  return 0;
}
