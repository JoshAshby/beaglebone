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
    int sendCmd(char what, int howmany);
    int waitForZeroCross(int howMany);
    int write(int val);

  public:
    x10(GPIO* zero, GPIO* tx);
    ~x10();

    int send(char house, char number);
};

#endif
