#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

using namespace std;

const string LED_DIR = "/sys/class/leds/";

int toggle_led(int led) {
  string fileTemp = LED_DIR + "beaglebone:green:usr";
  stringstream where;
  where << fileTemp << led << "/brightness";
  string filename = where.str();

  fstream brightnessFile(filename.c_str(), fstream::in | fstream::out);
  if(!brightnessFile.is_open()) {
    cout << "Couldn't open the brightness file";
    return -1;
  };

  while(brightnessFile.good()) {
    string val;
    getline(brightnessFile, val);
    int brightness = atoi(val.c_str());
    cout << brightness;
  };

  brightnessFile.close();
}

int main() {
  cout << "Hi beagle!\n";
  while(true) {
    toggle_led(0);
    sleep(5);
    toggle_led(0);
    sleep(5);
  }
  return 0;
}
