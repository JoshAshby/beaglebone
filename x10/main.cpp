#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "gpio.h"
#include "button.h"
#include "x10.h"

using namespace std;


int main() {
  cout << "Hi beagle! This is X10!" << endl;

  GPIO zero(1, 7);
  GPIO tx(1, 6);
  x10 x10Obj(&zero, &tx);

  Button whiteBtn(2, 7);
  whiteBtn.input();

  while(true) {
    if(whiteBtn.getValue())
      break;

    sleep(7);
    cout << "ALL OFF" << endl;
    x10Obj.send(x10::HOUSE_A, x10::ALL_LIGHTS_OFF, 2);
    sleep(5);

    cout << "ALL ON" << endl;
    x10Obj.send(x10::HOUSE_A, x10::ALL_LIGHTS_ON, 2);
  };

  return 0;
};
