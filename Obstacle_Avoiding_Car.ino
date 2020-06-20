#include <NewPing.h> //import the ultrasonic sensor library

//Assigning pins for the ultrasonic sensor
#define trig_pin A1 
#define echo_pin A2
#define maximum_distance 200

//newPing function
NewPing sonar(trig_pin, echo_pin, maximum_distance);

//Assigning pins for the L298N DC Motor Driver
const int LeftMotorForward = 6;
const int LeftMotorBackward = 7;
const int RightMotorForward = 5;
const int RightMotorBackward = 4;

boolean goesForward = false; //initialize variable to hold status of the car, regarding if it is moving forward or not
int distance = 100; //initialize variable to hold the distance reading

//setup function 
void setup(){
  
  //Serial output to the computer for ultrasonic sensor testing
  Serial.begin(9600);
  Serial.print("Setup Starting: ");

  //assign motor pins as output
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  delay(500);

  //Take three initial distance readings
  distance = readPing();
  delay(100);
  Serial.print(distance);
  Serial.print(" ");
  
  distance = readPing();
  delay(100);
  Serial.print(distance);
  Serial.print(" ");
  
  distance = readPing();
  delay(100);
  Serial.print(distance);
  Serial.print(" ");

  Serial.print(" Initialization Finished, Starting Loop: ");
}

//main loop - basic instructions for the car
void loop(){


  //take distance reading
  delay(25);
  distance = readPing();
  delay(25);
  Serial.print(distance);
  Serial.print(" ");

  //if the distance infront of the car is 20cm or smaller, make the car stop and turn to avoid hitting obstacle 
  if (distance <= 20){
    turn();
  }
  
  //if the distance infront of car is greater than 20cm, keep moving forward
  else {
   moveForward();
  }
}

//readPing function to get distance measurement
int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

//stop function 
void moveStop(){

  //set all pins to low to make motors halt
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

//move forard function 
void moveForward(){

  //check if the car is currently moving forward
  if(!goesForward){
    goesForward=true;

    //make both left and right motor spin backwards by setting both forward motor pins to high and backwards motor pins to low 
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  }
}

//move backward function 
void moveBackward(){
  goesForward=false;

  //make both left and right motors spin backwards by setting both backward motor pins to high and forward motor pins to low
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
}

//turn function
void turn() {
   moveStop();
   delay(300);
   moveBackward();
   delay(1000);
   moveStop();    
   delay(300);
   turnRight();
   moveStop();
   delay(300);
}

//turn right function 
void turnRight(){

  //make the car turn right by making left motor spin forward and right motor spin backward
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(500);
}

//turn left function 
void turnLeft(){

  //make the car turn left by making left motor spin backwards and right motor spin forwards
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(500);
}
