#pragma config(Sensor, in1,    Light_sensor,   sensorReflection)
#pragma config(Sensor, in2,    Potmeter_sensor, sensorPotentiometer)
#pragma config(Sensor, dgtl2,  QuadEncoder,    sensorNone)
#pragma config(Sensor, dgtl3,  LimitSwitch1,   sensorTouch)
#pragma config(Sensor, dgtl4,  LimitSwitch2,   sensorTouch)
#pragma config(Sensor, dgtl9,  sonarSensor,    sensorSONAR_mm)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port8,           Servo,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
void ServoMove(int servoPosition){
  writeDebugStreamLine("Servo Position = %d",servoPosition);
  motor[Servo] = servoPosition;
  wait1Msec(1000);
}
void turnright(){
	motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		wait1Msec(800);
		motor[leftMotor] = 120;  //right turn
		motor[rightMotor] = 120;
		wait1Msec(330);
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		wait1Msec(1000);
		}
	void turnaround(){
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		wait1Msec(800);
		motor[leftMotor] = 120;  // turn around
		motor[rightMotor] = 120;
		wait1Msec(610);
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		wait1Msec(1000);}
	void slightlyr(){
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		wait1Msec(800);
		motor[leftMotor] = 30;  //left turn
		motor[rightMotor] = 30;
		wait1Msec(330);
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		wait1Msec(100);
		}
		void slightlyl(){
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		wait1Msec(800);
		motor[leftMotor] = -30;  //right turn
		motor[rightMotor] = -30;
		wait1Msec(330);
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		wait1Msec(100);
		}
task main()
{
	int sonar_value;
	int left_switch;
	int right_switch;
	while(true){
	motor[leftMotor] = 50;
	motor[rightMotor] = -50;
	ServoMove(-127);
	ServoMove(0);
	ServoMove(127);
	left_switch  = SensorValue(LimitSwitch1);
	right_switch = SensorValue(LimitSwitch2);
	sonar_value = SensorValue(sonarSensor);
	if(left_switch == 1){
		slightlyr();
	}
	if(right_switch == 1){
		slightlyl();
	}
	if(sonar_value < 300 && sonar_value > 0){

	}
}
}
