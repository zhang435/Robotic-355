#pragma config(Motor,  port2,  Servo,               tmotorNormal, openLoop)
#pragma config(Sensor, in1,    Light_sensor,        sensorReflection)

void ServoMove(int servoPosition);

task main()
{
	int	light_value;
	int min = 1024;
	int position = -127;
	for (int i = -127; i<127 ; i +=10){
  	ServoMove(i);
  	light_value = SensorValue(Light_sensor);
  	if (light_value < min){
  		min = light_value;
  		position = i;}
   }
	ServoMove(position);
	}

void ServoMove(int servoPosition){

  writeDebugStreamLine("Servo Position = %d",servoPosition);
  motor[Servo] = servoPosition;
  wait1Msec(1000);
}
