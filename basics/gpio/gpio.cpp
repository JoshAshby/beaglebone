#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

#include "gpio.h"

using namespace std;

const std::string GPIO::GPIO_BASE_DIR      = "/sys/class/gpio/";
const std::string GPIO::GPIO_EXPORT_FILE   = GPIO_BASE_DIR + "export";
const std::string GPIO::GPIO_UNEXPORT_FILE = GPIO_BASE_DIR + "unexport";


GPIO::GPIO(int port, int portPin) : pin(port*32+pin),
  pinFolder((stringstream() << GPIO_BASE_DIR << "gpio" << pin).str()) {}

GPIO::~GPIO() {}

int GPIO::exportPin(void) {
  fstream exportFile(GPIO_EXPORT_FILE.c_str(), fstream::out);

  if(!exportFile.is_open()) {
    cout << "Couldn't open the gpio export file";
    return -1;
  };

  exportFile << pin;

  exportFile.close();

  stringstream folder;
  folder << GPIO_BASE_DIR << "gpio" << pin;
  const std::string pinFolder = folder.str();
}

int GPIO::unexportPin(void) {
  fstream unexportFile(GPIO_UNEXPORT_FILE.c_str(), fstream::out);

  if(!unexportFile.is_open()) {
    cout << "Couldn't open the gpio unexport file";
    return -1;
  };

  unexportFile << pin;

  unexportFile.close();
}
