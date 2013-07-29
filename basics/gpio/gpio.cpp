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


GPIO::GPIO(int port, int portPin) : pin(port*32+portPin) {
  exportPin();
}

GPIO::~GPIO() {
  unexportPin();
}

string GPIO::genFileStr(string filename) {
  stringstream folder;
  folder << GPIO_BASE_DIR << "gpio" << pin << "/" << filename;
  return folder.str();
}

int GPIO::exportPin(void) {
  fstream exportFile(GPIO_EXPORT_FILE.c_str(), fstream::out);

  if(!exportFile.is_open()) {
    cout << "Could not open the GPIO export file";
    return -1;
  };

  exportFile << pin;

  exportFile.close();
  return 0;
}

int GPIO::unexportPin(void) {
  fstream unexportFile(GPIO_UNEXPORT_FILE.c_str(), fstream::out);

  if(!unexportFile.is_open()) {
    cout << "Could not open the GPIO unexport file";
    return -1;
  };

  unexportFile << pin;

  unexportFile.close();
  return 0;
}

int GPIO::setDirection(bool which) {
  // This is probably highly wrong, but I guess I'll either find out the hard
  // way or through actually taking the time to read the sysfs driver manual
  fstream directionFile(genFileStr("direction").c_str(), fstream::out);

  if(!directionFile.is_open()) {
    cout << "Could not open the GPIO direction file";
    return -1;
  };

  if(which) {
    directionFile << "in";
  } else {
    directionFile << "out";
  }

  directionFile.close();
  return 0;
}

int GPIO::input(void) {
  return setDirection(true);
}

int GPIO::output(void) {
  return setDirection(false);
}

int GPIO::setHigh(void) {
  fstream valueFile(genFileStr("value").c_str(), fstream::out);

  if(!valueFile.is_open()) {
    cout << "Could not open the GPIO's value file";
    return -1;
  }

  valueFile << 1;

  valueFile.close();
  return 0;
}

int GPIO::setLow(void) {
  fstream valueFile(genFileStr("value").c_str(), fstream::out);

  if(!valueFile.is_open()) {
    cout << "Could not open the GPIO's value file";
    return -1;
  }

  valueFile << 0;

  valueFile.close();
  return 0;
}

int GPIO::toggle(void) {
  fstream valueFile(genFileStr("value").c_str(), fstream::out | fstream::in);

  if(!valueFile.is_open()) {
    cout << "Could not open the GPIO's value file";
    return -1;
  }

  string valStr;
  getline(valueFile, valStr);

  int val = atoi(valStr.c_str());
  if(val >= 1) {
    val = 0;
  } else {
    val = 1;
  }

  valueFile << val;

  valueFile.close();

  return 0;
}

int GPIO::getValue(void) {
  fstream valueFile(genFileStr("value").c_str(), fstream::in);

  if(!valueFile.is_open()) {
    cout << "Could not open the GPIO's value file";
    return -1;
  }

  string val;
  getline(valueFile, val);
  int value = atoi(val.c_str());

  valueFile.close();

  return value;
}
