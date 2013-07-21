#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>

#include "digital.h"

using namespace std;


int GPIO::exportGPIO(int pin) {
  fstream exportFile(GPIO_EXPORT_FILE.c_str(), fstream::out);

  if(!exportFile.is_open()) {
    cout << "Couldn't open the gpio export file";
    return -1;
  };

  exportFile.close();
}

int GPIO::unexportGPIO(int pin) {
  using namespace std;
  fstream unexportFile(GPIO_UNEXPORT_FILE.c_str(), fstream::out);

  if(!unexportFile.is_open()) {
    cout << "Couldn't open the gpio unexport file";
    return -1;
  };

  unexportFile.close();
}

GPIO gpio;
