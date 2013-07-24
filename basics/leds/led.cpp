#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

#include "led.h"

using namespace std;


LED::LED_DIR = "/sys/class/leds/";

LED::LED(int which) : led(pin) {}

LED::~LED() {}

int LED::setTrigger(std::string which) {
  string fileTemp = LED_DIR + "beaglebone:green:usr";
  stringstream brightWhere;
  brightWhere << fileTemp << led << "/brightness";
  string filename = brightWhere.str();

  stringstream where;
  where << fileTemp << led << "/trigger";
  string filenameToggle = where.str();

  fstream toggleFile(filenameToggle.c_str(), fstream::out);
  if(!toggleFile.is_open()) {
    cout << "Couldn't open the trigger file" << endl;
    return -1;
  };

  toggleFile << which;

  toggleFile.close();
  return 0;
}

int LED::on(void) {
  string fileTemp = LED_DIR + "beaglebone:green:usr";
  stringstream where;
  where << fileTemp << led << "/brightness";
  string filename = where.str();

  fstream brightnessFile(filename.c_str(), fstream::out);
  if(!brightnessFile.is_open()) {
    cout << "Couldn't open the brightness file" << endl;
    return -1;
  };

  brightnessFile << 1;

  brightnessFile.close();

  return 0;
}

int LED::off(void) {
  string fileTemp = LED_DIR + "beaglebone:green:usr";
  stringstream where;
  where << fileTemp << led << "/brightness";
  string filename = where.str();

  fstream brightnessFile(filename.c_str(), fstream::out);
  if(!brightnessFile.is_open()) {
    cout << "Couldn't open the brightness file" << endl;
    return -1;
  };

  brightnessFile << 0;

  brightnessFile.close();

  return 0;
}

int LED::toggle(void) {
  string fileTemp = LED_DIR + "beaglebone:green:usr";
  stringstream where;
  where << fileTemp << led << "/brightness";
  string filename = where.str();

  fstream brightnessFile(filename.c_str(), fstream::in | fstream::out);
  if(!brightnessFile.is_open()) {
    cout << "Couldn't open the brightness file" << endl;
    return -1;
  };

  string val;
  getline(brightnessFile, val);
  int brightness = atoi(val.c_str());
  if(brightness >= 1) {
    brightness = 0;
  } else {
    brightness = 1;
  };
  brightnessFile << brightness;

  brightnessFile.close();

  return 0;
}
