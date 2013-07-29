#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "gpio.h"

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

  for(int i=0; i<=2; i++) {
    colors[i]->setLow();
    sleep(5);
    colors[i]->setHigh();
  }

  //GPIO greenBtn(1, 3);
  //greenBtn.input();

  //GPIO redBtn(1, 7);
  //redBtn.input();

  //GPIO blueBtn(2, 4);
  //blueBtn.input();

  //GPIO whiteBtn(2, 3);
  //whiteBtn.input();

  //bool wClick = false;
  //while(!wClick) {
    //wClick = whiteBtn.getValue();
  //}

  //bool clicks[2];

  //while(true) {
    //clicks[0] = redBtn.getValue();
    //clicks[1] = blueBtn.getValue();
    //clicks[2] = greenBtn.getValue();

    //for(int i=0; i<=2; i++) {
      //if(clicks[i]) {
        //colors[i]->toggle();
      //}
    //}
  //}

  return 0;
}
