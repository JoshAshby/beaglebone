#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

using namespace std;

const string LED_DIR = "/sys/class/leds/";

int led_out(int led) {
  string fileTemp = LED_DIR + "beaglebone:green:usr";
  stringstream brightWhere;
  brightWhere << fileTemp << led << "/brightness";
  string filename = brightWhere.str();

  fstream brightnessFile(filename.c_str(), fstream::out);
  if(!brightnessFile.is_open()) {
    cout << "Couldn't open the brightness file";
    return -1;
  };

  brightnessFile << 0;

  brightnessFile.close();

  stringstream where;
  where << fileTemp << led << "/trigger";
  string filenameToggle = where.str();

  fstream toggleFile(filenameToggle.c_str(), fstream::out);
  if(!toggleFile.is_open()) {
    cout << "Couldn't open the trigger file";
    return -1;
  };

  toggleFile << "none";

  toggleFile.close();
  return 0;
}

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

  string val;
  getline(brightnessFile, val);
  int brightness = atoi(val.c_str());
  cout << brightness << endl;
  if(brightness >= 1) {
    brightness = 0;
  } else {
    brightness = 1;
  };
  brightnessFile << brightness;

  brightnessFile.close();

  return 0;
}

int main() {
  for(int i = 0; i <= 3; i++) {
    led_out(i);
  };

  cout << "Hi beagle!\n";

  while(true) {
    for(int i = 0; i <= 3; i++) {
      toggle_led(i);
      sleep(1);
      toggle_led(i);
    };
  };

  return 0;
}
