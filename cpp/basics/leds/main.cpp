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
  LED led(0);

  for(int i=0; i=9; i++) {
    led.on();
    sleep(5);
    led.off();
    sleep(5);
  }

  led.setTrigger("heartbeat");

  return 0;
}
