// I don't currently have a rustc compiler with me so this probably doesn't
// actually work at all. In fact, I'm pretty sure it'll throw exceptions out
// its ass if compiled. In the mean time, this should eventually be a Rust-lang
// similar library to what GPIO.cpp is for C++
use std::io::File;

let GPIO_Base: ~str = "/sys/class/gpio/"

enum Direction {
  input = "in",
  output = "out"
}

enum Value {
  high = "1",
  low = "0"
}

trait GPIO_pin {
  fn export(&self);
  fn unexport(&self);
  fn set_direction(&self, d: Direction);
  fn set_value(&self, v: Value);
  fn get_value(&self) -> (v: Value);
}

struct GPIO {
  pin: ~str
}

impl GPIO_pin for GPIO {
  fn new(pin: ~str) -> GPIO {
    GPIO{pin: &pin}
  }

  fn export(&self) {
    let export = GPIO_Base + "export";
    match File::open(&Path::new(export)).write(bytes!(self.pin)) {
      Ok(()) => (),
      Err(e) => println!("Failed to export pin: {}", e)
    }
  }

  fn unexport(&self) {
    let unexport = GPIO_Base + "unexport";
    match File::open(&Path::new(unexport)).write(bytes!(self.pin)) {
      Ok(()) => (),
      Err(e) => println!("Failed to unexport pin: {}", e)
    }
  }

  fn set_direction(&self, d: Direction) {
    let unexport = GPIO_Base + self.pin;
    match File::open(&Path::new(unexport)).write(bytes!(d)) {
      Ok(()) => (),
      Err(e) => println!("Failed to unexport pin: {}", e)
    }
  }

  fn set_value(&self, v: Value) {
    let unexport = GPIO_Base + self.pin;
    match File::open(&Path::new(unexport)).write(bytes!(v)) {
      Ok(()) => (),
      Err(e) => println!("Failed to unexport pin: {}", e)
    }
  }
}

fn main() {
  let p1 = GPIO::new(~"P8_13");
  p1.export();
  p1.set_direction(input);
  p1.unexport();
}
