#include <string>

#ifndef DIGITAL_H
#define DIGITAL_H

class GPIO {
  protected:
    std::string GPIO_BASE_DIR      = "/sys/class/gpio/";
    std::string GPIO_EXPORT_FILE   = GPIO_BASE_DIR + "export";
    std::string GPIO_UNEXPORT_FILE = GPIO_BASE_DIR + "unexport";

  public:
    int exportGPIO(int pin);
    int unexportGPIO(int pin);

    int outputGPIO(int pin);
    int inputGPIO(int pin);
};

#endif
