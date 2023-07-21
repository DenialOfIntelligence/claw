void setup() {
  pinMode(2, OUTPUT);   // M1
  pinMode(3, OUTPUT);   //     (PWM)
  pinMode(4, OUTPUT);   // M2
  pinMode(5, OUTPUT);   //     (PWM)
  pinMode(6, OUTPUT);   // PWM
  pinMode(9, OUTPUT);   // PWM
  pinMode(10, OUTPUT);  // PWM
  pinMode(11, OUTPUT);  // PWM
  pinMode(18, OUTPUT);  // M3
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);  // M4
  pinMode(21, OUTPUT);
}

int pwm(int x) {
  int out;
  if (x < 512) { //Check if joystick is above, below, or at the middle and calculate the unmapped output
    x = 512 - x;
  }
  if (x > 512) {
    x = x - 512;
  }
  if (x == 512) {
    x = 0;
  }
  out = map(x, 0, 1023, 50, 120); //Map the output to a PWM value
  return out; //Return the value
}

void loop() {
  if (analogRead(A0) < 100) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    analogWrite(6, pwm(analogRead(A0)));
  }

  if (analogRead(A0) > 700) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    analogWrite(6, pwm(analogRead(A0)));
  }

  if (analogRead(A1) < 100) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    analogWrite(9, pwm(analogRead(A1)));
  }

  if (analogRead(A1) > 700) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    analogWrite(9, pwm(analogRead(A1)));
  }

  if (analogRead(A2) < 100) {
    digitalWrite(18, LOW);
    digitalWrite(19, HIGH);
    analogWrite(10, pwm(analogRead(A2)));
  }

  if (analogRead(A2) > 700) {
    digitalWrite(18, HIGH);
    digitalWrite(19, LOW);
    analogWrite(10, pwm(analogRead(A2)));
  }

  if (analogRead(A3) < 100) {
    digitalWrite(20, HIGH);
    digitalWrite(21, LOW);
    analogWrite(11, pwm(analogRead(A3)));
  }

  if (analogRead(A3) > 700) {
    digitalWrite(20, HIGH);
    digitalWrite(21, LOW);
    analogWrite(11, pwm(analogRead(A3)));
  }

  delay(100);
}
