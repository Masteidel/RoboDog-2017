//import ax12 library to send DYNAMIXEL commands
#include <ax12.h>

unsigned long lastTime;
double input, output, setPoint;
double errSum, lastErr;
double kp, ki, kd;

void setup() {
	Serial.begin(9600);
	SetPosition(1,0);//set the position of servo # 1 to '0'
	delay(100);//wait for servo to move

}

void loop() {
	//increment from 0 to 340
	//causes servo to rotate approximately 30 degrees counterclockwise
	for(int i=0;i<340;i++) {
		Serial.println(GetPosition(1));//Prints current position to the serial monitor
		SetPosition(1,i);//set the position of servo #1 to the current value of 'i'
		delay(10);//wait for servo to move
	}
	//decrement from 340 to 0
	//causes servo to rotate approximately 30 degrees clockwise
	for(int i=340;i>0;i--) {
		Serial.println(GetPosition(1));//Prints current position to the serial monitor
		SetPosition(1,i);//set the position of servo #1 to the current value of 'i'
		delay(10);//wait for servo to move
	}
}
