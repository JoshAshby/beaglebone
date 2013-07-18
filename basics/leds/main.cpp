#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

const string LED_DIR = "/sys/class/leds/";

int toggle_led(int led) {
  string fileBase = "beaglebone:green:usr";
  string brightness = "/brightness";
  char numStr[2];
  sprintf(numStr, "%d", led);
  string filename = LED_DIR + fileBase + numStr + brightness;

  ifstream file(filename);
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
