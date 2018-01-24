//import ax12 library to send DYNAMIXEL commands
#include <ax12.h>
#include <PID_v1.h>

double SetPoint, Input, Output;
PID pid(&Input, &Output, &SetPoint, 1, 0, 0, DIRECT);

void setup() {
	Serial.begin(9600);
	SetPosition(1,0);//set the position of servo # 1 to '0'
	delay(100);//wait for servo to move
	Input = GetPosition(1);
	SetPoint = 1024;
	pid.SetMode(AUTOMATIC);

}

void loop() {
	if(GetPosition(1) == 0) {
		SetPoint = 1024;
	}
	else if(GetPosition(1) == 1024) {
		SetPoint = 0;
	}
	Input = GetPosition(1);
	pid.Compute();
	SetPosition(1, Output);
	Serial.print("Input: ");
	Serial.println(Input);
	Serial.print("Output: ");
	Serial.println(Output);
	Serial.print("SetPoint: ");
	Serial.println(SetPoint);
	Serial.println();
}
