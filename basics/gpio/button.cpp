#include "button.h"

using namespace std;


const int Button::max = 8;


Button::Button(int port, int portPin) : GPIO(port, portPin) {
  exportPin();
}

Button::~Button() {
  unexportPin();
}

int Button::debounce(void) {
  int integrator = 0;
  int output     = 0;

  for(int i=0; i < max; i++) {
    if (getValue()) {
      if (integrator > 0) {
        integrator--;
      }
    } else if (integrator < max) {
      integrator++;
    }
  }
  if (integrator == 0) {
    output = 0;
  } else if (integrator >= max) {
    integrator = max;
    output = 1;
  }
  return output;
}
