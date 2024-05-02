#define m1 4 //Right Motor MA1
#define m2 5 //Right Motor MA2
#define m3 2 //Left Motor MB1
#define m4 3 //Left Motor MB2
#define e1 9 //Right Motor Enable Pin EA
#define e2 10 //Left Motor Enable Pin EB
//**********5 Channel IR Sensor Connection**********//
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4
//*************************************************//
void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
}
void loop() {
  //Reading Sensor Values
  int s1 = digitalRead(ir1); //Left Most Sensor
  int s2 = digitalRead(ir2); //Left Sensor
  int s3 = digitalRead(ir3); //Middle Sensor
  int s4 = digitalRead(ir4); //Right Sensor
  int s5 = digitalRead(ir5); //Right Most Sensor

  // Adjust the speed of the motors from 0-255
  int motorSpeed = 255;

  // Enable both motors
  analogWrite(e1, motorSpeed);
  analogWrite(e2, motorSpeed);

  // If only middle sensor detects black line
  if (s1 == HIGH && s2 == HIGH && s3 == LOW && s4 == HIGH && s5 == HIGH) {
    // Going forward with full speed 
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }
  // If only left sensor detects black line
  else if (s1 == HIGH && s2 == LOW && s3 == HIGH && s4 == HIGH && s5 == HIGH) {
    // Going right with full speed 
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
  // If only left most sensor detects black line
  else if (s1 == LOW && s2 == HIGH && s3 == HIGH && s4 == HIGH && s5 == HIGH) {
    // Going right with full speed 
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
  }
  // If only right sensor detects black line
  else if (s1 == HIGH && s2 == HIGH && s3 == HIGH && s4 == LOW && s5 == HIGH) {
    // Going left with full speed 
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }
  // If only right most sensor detects black line
  else if (s1 == HIGH && s2 == HIGH && s3 == HIGH && s4 == HIGH && s5 == LOW) {
    // Going left with full speed 
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }
  // If middle and right sensor detects black line
  else if (s1 == HIGH && s2 == HIGH && s3 == LOW && s4 == LOW && s5 == HIGH) {
    // Going left with full speed 
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }
  // If middle and left sensor detects black line
  else if (s1 == HIGH && s2 == LOW && s3 == LOW && s4 == HIGH && s5 == HIGH) {
    // Going right with full speed 
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
  // If middle, left, and left most sensor detects black line
  else if (s1 == LOW && s2 == LOW && s3 == LOW && s4 == HIGH && s5 == HIGH) {
    // Going right with full speed 
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
  // If middle, right, and right most sensor detects black line
  else if (s1 == HIGH && s2 == HIGH && s3 == LOW && s4 == LOW && s5 == LOW) {
    // Going left with full speed 
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }
  // If all sensors are on a black line
  else if (s1 == LOW && s2 == LOW && s3 == LOW && s4 == LOW && s5 == LOW) {
    // Stop
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
}
