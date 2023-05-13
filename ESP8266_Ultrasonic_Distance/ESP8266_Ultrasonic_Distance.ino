/*
This Arduino code measures the distance using an ultrasonic sensor and displays the results in both centimeters and inches.
It utilizes the HC-SR04 ultrasonic sensor and calculates the distance based on the time taken for the sound wave to travel.

Author: Sinku Kumar
Date: May 12, 2023
*/

// Hardware connections:
// - TRIG pin of the sensor connected to pin 12 of the Arduino board
// - ECHO pin of the sensor connected to pin 14 of the Arduino board

#define TRIG 12
#define ECHO 14
#define SOUND_VELOCITY 0.034 // cm/uS
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  /*
  Initializes the serial communication and sets up the pin modes.
  */
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  /*
  Performs the distance measurement and displays the results.
  */
  // Reset the trigger and make a short pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  // Read the echo, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO, HIGH);
  
  // Distance calculation in cm and inch
  distanceCm = duration * SOUND_VELOCITY / 2;
  distanceInch = distanceCm * CM_TO_INCH;
  
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  //Serial.print("Distance (inch): ");
  //Serial.println(distanceInch); 
  delay(100);
}
