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

  led.high();
  sleep(5);
  led.low();

  led.unexportPin();
  return 0;
}
