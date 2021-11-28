#include<Servo.h>

Servo myservo;
const int trig_pin = 2;
const int echo_pin = 3;
long duration, cm, inches, d;
int max_dist = 100;
void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  myservo.attach(6);
}
void loop() {
  for (int i = 0; i < 180; i++) {
    myservo.write(i);
    d = calculate_distance();
    cm = (d / 2) / 29.1;
    inches = (d / 2) / 74;
    if (cm <= max_dist) {
      Serial.print("Object found at ");
      Serial.print(i);
      Serial.println(" Angle");
      Serial.print("Distance is ");
      Serial.print(cm);
      Serial.println(" CM");
    }
    delay(100);
  }
  for (int i = 180; i > 0; i--) {
    myservo.write(i);
    d = calculate_distance();
    cm = (d / 2) / 29.1;
    inches = (d / 2) / 74;
    if (cm <= max_dist) {
      Serial.print("Object found at ");
      Serial.print(i);
      Serial.println(" Angle");
      Serial.print("Distance is ");
      Serial.print(cm);
      Serial.println(" CM");
    }
    delay(100);
  }
}
long calculate_distance() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(5);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  pinMode(echo_pin, INPUT);
  duration = pulseIn(echo_pin, HIGH);
  return duration;
}
