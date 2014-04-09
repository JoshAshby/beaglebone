#include <unistd.h>
#include "button.h"

using namespace std;


const int Button::max = 150;

Button::Button(int port, int portPin) : GPIO(port, portPin) {
  exportPin();
}

Button::~Button() {
  unexportPin();
}

int Button::debounce(void) {
  int check;
  int click = getValue();
  if(click) {
    usleep(max * 1000);
    check = getValue();
    if(check==click) {
      return 1;
    }
    return 0;
  }
  return 0;
}
