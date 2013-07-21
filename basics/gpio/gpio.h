#include <string>

#ifndef GPIO_H
#define GPIO_H

class GPIO {
  private:
    int pin = 0;

  protected:
    std::string GPIO_BASE_DIR      = "/sys/class/gpio/";
    std::string GPIO_EXPORT_FILE   = GPIO_BASE_DIR + "export";
    std::string GPIO_UNEXPORT_FILE = GPIO_BASE_DIR + "unexport";

  public:
    GPIO(char port, int portPin);
    ~GPIO();

    int exportPin(void);
    int unexportPin(void);
};

#endif
