#include <string>

#ifndef LED_H
#define LED_H


class LED {
  protected:
    const static std::string LED_DIR;
    const int led;

  public:
    LED(int which);
    ~LED();

    int setTrigger(std::string which);

    int on(void);
    int off(void);

    int toggle(void);
};

#endif
