#include <iostream>

#include "gpio.h"

using namespace std;

int main() {
  cout << "Hi beagle!" << endl;

  GPIO led(8, 1);
  led.exportPin();

  led.unexportPin();
  return 0;
}
