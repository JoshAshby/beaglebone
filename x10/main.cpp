#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "gpio.h"
#include "button.h"
#include "x10.h"

using namespace std;


int main() {
  cout << "Hi beagle!" << endl;

  GPIO zero(1, 7);
  GPIO tx(1, 3);
  x10 x10Obj(&zero, &tx);

  GPIO red(2, 10);
  red.output();
  red.setHigh();

  GPIO blue(2, 8);
  blue.output();
  blue.setHigh();

  GPIO green(2, 6);
  green.output();
  green.setHigh();

  GPIO* colors[] = {&red, &blue, &green};


  Button redBtn(2, 13);
  redBtn.input();

  Button blueBtn(2, 11);
  blueBtn.input();

  Button greenBtn(2, 9);
  greenBtn.input();

  Button whiteBtn(2, 7);
  whiteBtn.input();

  bool clicks[3];
  while(true) {
    if(whiteBtn.getValue())
      break;

    clicks[0] = redBtn.debounce();
    clicks[1] = blueBtn.debounce();
    clicks[2] = greenBtn.debounce();

    if(clicks[0]) {
      x10Obj.send(0b0110, 0b00011);
    }
    if(clicks[1]) {
      x10Obj.send(0b0110, 0b00001);
    }
  }

  return 0;
}
