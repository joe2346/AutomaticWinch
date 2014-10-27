// Do not remove the include below
#include "Winch.h"

#include <Event.h> // event library for Timer library
#include <Timer.h> // Timer library
#include <Servo.h> // servo control library
#include <Encoder.h> // encoder library

long setPosition=0,currentPosition = 0,rawEncoder;
//setpostion variable
//current position based on encoder variable
//encoder variable
int potVal ; // potentiomet value max 1024
long timeMult, waitTime = 60; // time to wait between movments seconds
const int encA = 2,encB = 3, potPin = 0,manualcontrolpin=13,timeMultPin=12;
//encA & encB pins
//Manual control potentiometer pin
//switch pin for manual mode, internal pllup
const int P = 90,length = 48,positionIncrement = 12;
//P =Postion gain factor
//overall length of winch motion
// movment in inch per waitTime
boolean dir; // boolean for direction of winch

Servo winchMotor; // winch servo object
Encoder myEnc(encA,encB); // Encoder object for position
Timer timer; //Timer object for motion timing

// function 1
// Gets the current encoder reading and converts to pos in inches
long currentPos(long rEnc){
long posinch =(rEnc * .0006875);
return posinch;
}


// function 2
// moves winch to current set position
void setposition(long setPos,long curPos){
 long error = curPos-setPos; // calculates error
 long  motorVal; //error to motor value
 //  Serial.println("pos:");  // debug prints
 //   Serial.println(curPos);
 //    Serial.println("set:");
 //    Serial.println(setPos);
  while(abs(error)>=1){   //correct eroor to less than 1 in.
curPos=currentPos(myEnc.read()); //
error = curPos-setPos;
error = error * P;
motorVal = error + 90;
  if (motorVal > 180){
  motorVal=180;}
  if (motorVal < 0){
  motorVal = 0;}
winchMotor.write(motorVal);
   Serial.print("motorVal:");
    Serial.println(motorVal);
}
}


// function 3
// manual control of winch
void manualControl(void){
   digitalRead(manualcontrolpin); // check manual control switch
  while(digitalRead(manualcontrolpin)==0){ // check for manual control switch
        Serial.println("Manual Control: "); // debug Manual control
    digitalRead(manualcontrolpin); // check manual control switch
    potVal = analogRead(potPin); // read potentiometer for manual control
    if (potVal >=100 && potVal < 300){ // reverse slow
   winchMotor.write(50);
   Serial.print("motor Value: ");
  Serial.println("50");
  }
    if (potVal >=0 && potVal < 100){ // reverse fast
   winchMotor.write(0);
    Serial.print("motor Value: ");
  Serial.println("0");
  }
    if (potVal >700 && potVal < 900){ // forward slow
   winchMotor.write(130);
   Serial.print("motor Value: ");
  Serial.println("130");
  }
    if (potVal >= 900 && potVal < 1025){ // forward fast
   winchMotor.write(180);
    Serial.print("motor Value: ");
  Serial.println("180");
   }
    if (potVal >= 300 && potVal <= 700){ // stop
      winchMotor.write(90);
      Serial.print("motor Value: ");
  Serial.println("90");
   }
 }
delay(125);
 }

 //function 4
 // timer function
 // update position
 void timerfunction(void){
   Serial.println("Timer triggerd"); // timer debug
  if (setPosition <= 0){ // set direction forward when at 0
  dir = 1; // 1 = forward
 }
  if(setPosition >= length ){ // set direction reversal by length
   dir = 0;// 0 = reverse
  }
 if (dir == 1){ // increment position for forward
  setPosition = setPosition+positionIncrement;
 }
  if (dir == 0){  // deincrement position for reverse
  setPosition = setPosition-positionIncrement;
 }
 }


//The setup function is called once at startup of the sketch
void setup()
{
	  Serial.begin(9600); // serial at buad 9600 for debug
	  Serial.println("Starting:"); // starting print
	 pinMode(timeMultPin,INPUT_PULLUP);  //time speed up debug switch configured with internal pullup resistor
	 pinMode(manualcontrolpin,INPUT_PULLUP); // manual control switch configured with internal pullup resistor
	 if(digitalRead(timeMultPin)==0){// debug switch, 1min for 1 hour
	  timeMult=1;
	 }
	   else{
	   timeMult=60;
	  }
	   winchMotor.attach(9,1000,2000); // configure servo pin and signal 1000-2000us pulses
	   waitTime=waitTime*timeMult; // debug switch, 1min for 1 hour
	   Serial.print("waitTime: ");
	   Serial.println(waitTime);
	   timer.every(1000*waitTime,timerfunction); // timer configure wait time converted to seconds

	 }



// The loop function is called in an endless loop
void loop()
{

	currentPosition=currentPos(myEnc.read()); // reads encoder and converts
	  setposition(setPosition,currentPosition); // moves winch to position
	 timer.update(); //timer function updates position
	 manualControl(); // checks manual control
	     Serial.print("setPosition: "); // debug positions
	      Serial.println(setPosition);
	    Serial.print("currentPosition: ");
	      Serial.println(currentPosition);
	 delay(150); // slight delay for debug readability
}
