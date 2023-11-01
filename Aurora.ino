//Project 1 for instrumnetation Lab  

// Savanna, Beverly & Alexis  

// 25th October, 2023 

#include <NewPing.h>                // Used as an interface with the ultrasonic sensor, which helps us measure the distance to obstacles 

 

#define TRIGGER_PIN 6               // Choosing a trigger pin 

#define ECHO_PIN 7                  // Stating the pin on arduino that will be connected to echo sensor 

#define MAX_DISTANCE 200           // Stating the maximum distance between Aurora and Obstacle   

 
 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

 
 

#define motor1Pin1 2              // Stating the pin on arduino that will be connected to right back wheel 

#define motor1Pin2 3              // Stating the pin on arduino that will be connected to right front wheel 

#define motor2Pin1 4              // Stating the pin on arduino that will be connected to left front wheel 

#define motor2Pin2 5              // Stating the pin on arduino that will be connected to left back wheel 

 
 

void setup() { 

  // Initialize motor control pins as outputs 

  pinMode(motor1Pin1, OUTPUT);       // Setting pin for right back wheel as an output pin 

  pinMode(motor1Pin2, OUTPUT);       // Setting pin for right front wheel as an output pin 

  pinMode(motor2Pin1, OUTPUT);       // Setting pin for left front wheel as an output pin 

  pinMode(motor2Pin2, OUTPUT);       // Setting pin for left back wheel as an output pin 

} 

 
 

void loop() { 

  unsigned int uS = sonar.ping(); 

  int distance = uS / US_ROUNDTRIP_CM; 

 
 

  if (distance < 10) {                

    // Obstacle detected, stop the motors 

    stopMotors(); 

    delay(500); 

    // Turn right 

    turnRight(); 

    delay(1000); 

  } else { 

    // No obstacle, move forward 

    moveForward(); 

  } 

} 

 
 

void moveForward() { 

  digitalWrite(motor1Pin1, HIGH);    //Setting pin for right back wheel for 5 volts 

  digitalWrite(motor1Pin2, LOW);     //Setting pin for right front wheel for 0 volts 

  digitalWrite(motor2Pin1, HIGH);    //Setting pin for left front wheel for 5 volts 

  digitalWrite(motor2Pin2, LOW);     //Setting pin for left back wheel for 0 volts 

} 

 
 

void stopMotors() { 

  digitalWrite(motor1Pin1, LOW);      //Setting pin for right back wheel for 0 volts  

  digitalWrite(motor1Pin2, LOW);      //Setting pin for right front wheel for 0 volts 

  digitalWrite(motor2Pin1, LOW);      //Setting pin for left front wheel for 0 volts 

  digitalWrite(motor2Pin2, LOW);      //Setting pin for left back wheel for 0 volts 

} 

 
 

void turnRight() { 

  digitalWrite(motor1Pin1, HIGH);      //Setting pin for right back wheel for 5 volts    

  digitalWrite(motor1Pin1, HIGH);      //Setting pin for right back wheel for 5 volts  

  digitalWrite(motor1Pin2, LOW);       //Setting pin for right front wheel for 0 volts 

  digitalWrite(motor2Pin1, LOW);       //Setting pin for left front wheel for 5 volts 

  digitalWrite(motor2Pin2, HIGH);      //Setting pin for left back wheel for 5 volts 

} 
