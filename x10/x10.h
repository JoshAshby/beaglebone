#include <string>
#include "gpio.h"

#ifndef X10_H
#define X10_H


class x10 {
  protected:
    static const char startCode = 0b1110;
    static const char BRIGHT    = 0b01011;
    static const char DIM       = 0b01001;
    static const int  TIME      = 850;

    GPIO* zeroPin;
    GPIO* txPin;
    int sendStartCmd(void);
    int sendHouse(char what);
    int sendKey(char what);
    int waitForZeroCross(int howMany);
    int write(char val);

  public:
    x10(GPIO* zero, GPIO* tx);
    ~x10();

    int send(char house, char number, int times);
};

#endif
