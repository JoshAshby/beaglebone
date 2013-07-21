#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

#include "gpio.h"

using namespace std;


GPIO::GPIO(char port, int portPin) {
  port = port - 8;
  int pin = portPin;
}

GPIO::~GPIO() {
  delete &pin;
}

int GPIO::exportPin(void) {
  fstream exportFile(GPIO_EXPORT_FILE.c_str(), fstream::out);

  if(!exportFile.is_open()) {
    cout << "Couldn't open the gpio export file";
    return -1;
  };

  exportFile << pin;

  exportFile.close();
}

int GPIO::unexportPin(void) {
  using namespace std;
  fstream unexportFile(GPIO_UNEXPORT_FILE.c_str(), fstream::out);

  if(!unexportFile.is_open()) {
    cout << "Couldn't open the gpio unexport file";
    return -1;
  };

  unexportFile << pin;

  unexportFile.close();
}
