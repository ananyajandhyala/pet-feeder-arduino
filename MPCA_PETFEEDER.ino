#include <Servo.h>
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int sensor = 5;              // the pin that the sensor is atteched to pir
int val = 0; 
int ldrStatus =0;// variable to store the sensor status (value) pir data
int pos = 0;    // variable to store the servo position
const int ldrPin = A0; //light sensor
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {//pinmode helps setup each pin as ip or op
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(sensor, INPUT);    // initialize sensor as an input
  pinMode(ldrPin, INPUT);
  myservo.attach(10);  // attaches the servo on pin 10 to the servo object
  Serial.begin(9600);        // initialize serial baudrate =9600 is the value given which freq at which info transmitted
}

void loop() {//main func
  ldrStatus = digitalRead(ldrPin); //analogread takes value in terms of a number
  val = digitalRead(sensor);   // read sensor value reads pir

if (ldrStatus == HIGH)
  {
    if (val == HIGH) // check if the sensor is HIGH
    {
      //      Serial.print("Candela");
      Serial.println("The servo is on");
      myservo.write(0); //moves the servo rotator to a particular angle. ie 0 degree here
      delay(500);                // delay 500 milliseconds
    }
    else
    {
      myservo.write(120);
      Serial.println("The servo is off");
      delay(500);             // delay 500 milliseconds
    }

  }

  else
  {
    myservo.write(150);
      Serial.print("Candela");
      Serial.println(ldrStatus);
  }
  // calculates the ultrasonic distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH); //finds how long the pulse takes to come back.
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.println(val);
}
