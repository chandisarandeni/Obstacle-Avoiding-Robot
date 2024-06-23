/*
  @ Developed by CR
  -- obstacle avoiding robot
  -- Arduino
*/
#include <Servo.h>
#include <Ultrasonic.h>

Servo s = Servo();
Ultrasonic u = Ultrasonic(2, 3);

#define ENA 11 // LHS
#define in1 12
#define in2 13

#define ENB 10 // RHS
#define in3 8
#define in4 9

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  s.attach(4);

  pinMode(ENA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  analogWrite(ENA, 300); // Adjusted PWM value to fit 8-bit range (0-255)
  analogWrite(ENB, 255);
}

void loop() {
  // put your main code here, to run repeatedly:

  int x = Serial.read();

  if (x == '1') { // forward
    s.write(90);
    delay(400);
    int d = u.read();

    if (d > 10) {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      delay(500);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      delay(500);
    } else {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      delay(500);
    }
  }

  if (x == '2') { // backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(500);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(500);
  }
}
