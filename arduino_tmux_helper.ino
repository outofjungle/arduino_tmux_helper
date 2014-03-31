
//
// tmux helper for open/close window
//

const int pin2 = 2;
const int pin3 = 3;

int pin2_old_state = HIGH;
int pin3_old_state = HIGH;

void setup() {
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  Keyboard.begin();
}

void loop() {
  int pin2_state = digitalRead(pin2);
  int pin3_state = digitalRead(pin3);

  if ((pin2_state != pin2_old_state) && (pin2_state == HIGH)) {
    new_window();
  }
  
  if ((pin3_state != pin3_old_state) && (pin3_state == HIGH)) {
    close_window();
  }
  
  pin2_old_state = pin2_state; 
  pin3_old_state = pin3_state; 
}

void send_prefix() {
  Keyboard.press(KEY_LEFT_CTRL);
  delay(100);
  Keyboard.press('s');
  delay(100);
  Keyboard.releaseAll();
  delay(100);
}

void new_window() {
  send_prefix();
  Keyboard.press('c');
  delay(100);
  Keyboard.releaseAll();
  delay(100);
}

void close_window() {
  send_prefix();
  Keyboard.press('x');
  delay(100);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.press('y');
  Keyboard.releaseAll();
}
