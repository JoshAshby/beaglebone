#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "gpio.h"
#include "button.h"

using namespace std;


int main() {
  cout << "Hi beagle!" << endl;

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

    for(int i=0; i<=2; i++) {
      if(clicks[i]) {
        colors[i]->toggle();
      }
    }
  }

  return 0;
}
