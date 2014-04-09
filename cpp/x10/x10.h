#include <string>
#include "gpio.h"

#ifndef X10_H
#define X10_H


class x10 {
  protected:
    static const char startCode = 0b1110;
    //static const char BRIGHT    = 0b01011;
    //static const char DIM       = 0b01001;
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

    enum commands {
      ALL_UNITS_OFF  = 0b00001,
      ALL_LIGHTS_OFF = 0b01101,
      ALL_LIGHTS_ON  = 0b00011,
      ON             = 0b00101,
      OFF            = 0b00111,
      DIM            = 0b01001,
      BRIGHT         = 0b01011
    };

    enum units {
      U1  = 0b01100,
      U2  = 0b11100,
      U3  = 0b00100,
      U4  = 0b10100,
      U5  = 0b00010,
      U6  = 0b10010,
      U7  = 0b01010,
      U8  = 0b11010,
      U9  = 0b01110,
      U10 = 0b11110,
      U11 = 0b00110,
      U12 = 0b10110,
      U13 = 0b00000,
      U14 = 0b10000,
      U15 = 0b01000,
      U16 = 0b11000
    };

    enum house_codes {
      HOUSE_A = 0b0110,
      HOUSE_B = 0b1110,
      HOUSE_C = 0b0010,
      HOUSE_D = 0b1010,
      HOUSE_E = 0b0001,
      HOUSE_F = 0b1001,
      HOUSE_G = 0b0101,
      HOUSE_H = 0b1101,
      HOUSE_I = 0b0111,
      HOUSE_J = 0b1111,
      HOUSE_K = 0b0011,
      HOUSE_L = 0b1011,
      HOUSE_M = 0b0000,
      HOUSE_N = 0b1000,
      HOUSE_O = 0b0100,
      HOUSE_P = 0b1100
    };
};

#endif
