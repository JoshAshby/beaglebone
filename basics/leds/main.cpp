#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

const string LED_DIR = "/sys/class/leds/";

int toggle_led(int led) {
  string filetemp = LED_DIR + "beaglebone:green:usr%d/brightness";
  char numStr[50];
  sprintf(numStr, filetemp.c_str(), led);

  ifstream file(numStr);
  if(!file.is_open()) {
    cout << "Can't open brightness file";
    return -1;
  }
  while(file.good()) {
    string val;
    getline(file, val);
    cout << val;
  }
  file.close();
}

int main() {
  cout << "Hi beagle!\n";
  toggle_led(0);
  return 0;
}
