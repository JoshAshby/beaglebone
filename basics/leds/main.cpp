#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

#include "led.h"

using namespace std;


int main() {
  cout << "Hi beagle!" << endl;

  while(true) {
    LED led(0);
    led.on();
    sleep(5);
    led.off();
    sleep(5);
  }

  return 0;
}
