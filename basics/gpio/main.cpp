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

  while(true) {
    cout << led.getValue();
  }

  led.unexportPin();
  return 0;
}
