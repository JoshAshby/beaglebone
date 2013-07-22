#include <string>

#ifndef GPIO_H
#define GPIO_H


class GPIO {
  protected:
    const int pin;
    static const std::string GPIO_BASE_DIR;
    static const std::string GPIO_EXPORT_FILE;
    static const std::string GPIO_UNEXPORT_FILE;

  public:
    GPIO(int port, int portPin);
    ~GPIO();

    int exportPin(void);
    int unexportPin(void);

    int high(void);
    int low(void);

    int input(void);
    int output(void);
};

#endif
