#include <string>

#ifndef GPIO_H
#define GPIO_H

class GPIO {
  protected:
    static const std::string GPIO_BASE_DIR;
    static const std::string GPIO_EXPORT_FILE;
    static const std::string GPIO_UNEXPORT_FILE;

    const int pin;

    std::string genFileStr(std::string filename);

  public:
    enum direction {IN, OUT} pinDirection;
    GPIO(int port, int portPin);
    ~GPIO();

    int exportPin(void);
    int unexportPin(void);

    int setDirection(direction which);

    int input(void);
    int getValue(void);

    int output(void);
    int setHigh(void);
    int setLow(void);
    int toggle(void);
};

#endif
