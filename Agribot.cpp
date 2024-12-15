#include <Servo.h> 
Servo myservo; 
bool runServo = false; 
int motorPin1 = 9; // Motor 1 direction pin 
int motorPin2 = 10; // Motor 1 PWM pin 
int motorPin3 = 11; // Motor 2 direction pin 
int motorPin4 = 12; // Motor 2 PWM pin 
void setup() { 
Serial.begin(9600); 
myservo.attach(8); 
pinMode(motorPin1, OUTPUT); 
pinMode(motorPin2, OUTPUT); 
pinMode(motorPin3, OUTPUT); 
pinMode(motorPin4, OUTPUT); 
myservo.write(0); 
} 
void loop() { 
if (Serial.available()) { 
char c = Serial.read(); 
Serial.println(c); 
if (c == 'F') { 
// Move forward 
moveForward(); 
} else if (c == 'B') { // Move backward 
moveBackward(); 
} else if (c == 'L') { // Turn left 
turnLeft(); 
} else if (c == 'R') { // Turn right 
turnRight(); 
} else if (c == 'S') { // Stop 
stopMotors();} else if (c == 'A') { // Run servo 
rServo(); 
} else if (c == 'X') { // Stop servo 
sServo(); 
} 
} 
} 
void moveForward() { 
digitalWrite(motorPin1, HIGH); 
digitalWrite(motorPin2, LOW); 
digitalWrite(motorPin3, HIGH); 
digitalWrite(motorPin4, LOW); 
} 
void moveBackward() { 
digitalWrite(motorPin1, LOW); 
digitalWrite(motorPin2, HIGH); 
digitalWrite(motorPin3, LOW); 
digitalWrite(motorPin4, HIGH); 
} 
void turnLeft() { 
digitalWrite(motorPin1, LOW); 
digitalWrite(motorPin2, HIGH); 
digitalWrite(motorPin3, HIGH); 
digitalWrite(motorPin4, HIGH); 
} 
void turnRight() { 
digitalWrite(motorPin1, HIGH); 
digitalWrite(motorPin2, HIGH); 
digitalWrite(motorPin3, LOW); 
digitalWrite(motorPin4, HIGH); 
} 
void stopMotors() { 
digitalWrite(motorPin1, LOW); 
digitalWrite(motorPin2, LOW); 
digitalWrite(motorPin3, LOW); 
digitalWrite(motorPin4, LOW); 
} 
void rServo() { 
while(1) 
{ 
for (int i = 0; i <= 90; i++) { 
myservo.write(i); 
delay(10); 
} 
for (int i = 90; i >= 0; i--) { 
myservo.write(i); 
delay(10); 
} 
if (Serial.available()) 
{ 
char c = Serial.read(); 
if (c == 'X') 
{ 
sServo(); 
break; 
} 
} 
} 
} 
void sServo() { 
myservo.write(0); 
} 

