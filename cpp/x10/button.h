#include "gpio.h"

#ifndef BUTTON_H
#define BUTTON_H


class Button : public GPIO {
  protected:
    static const int max;

  public:
    Button(int port, int portPin);
    ~Button();

    int debounce(void);
};

#endif
