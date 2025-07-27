#include <Servo.h>
Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(9); // Servo on pin 9
  myServo.write(0); // Start at 0 degrees
}

void loop() {
  int sensorValue = 0;
  for (int i = 0; i < 10; i++) {
    sensorValue += analogRead(A3);
    delay(1);
  }
  sensorValue /= 10; // Average over 10 readings

  // Control servo based on EMG threshold
  if (sensorValue >= 350) {
    myServo.write(90); // Move to 90 degrees
  } else {
    myServo.write(0); // Reset to 0 degrees
  }

  // Output for Serial Plotter
  Serial.println(sensorValue);
  delay(10); // Fast updates
}