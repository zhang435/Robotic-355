#pragma config(Sensor, in1,    Light_sensor,   sensorReflection)
#pragma config(Sensor, in2,    Potmeter_sensor, sensorPotentiometer)
#pragma config(Sensor, dgtl2,  QuadEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  sonarSensor,    sensorSONAR_mm)
#pragma config(Motor,  port1,           rightMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port2,           Servo,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void ServoMove(int servoPosition);

task main()
{
	int distance = 0;
	short sensor_value;
	while(true){
	int	encoder_value;
	SensorValue[QuadEncoder] = 0;
	int	light_value;
	int	potmeter_value;
	int min = 1024; //maxmum the light value
	int position = -127; // initial the position
	int pot = 3000;
		motor[leftMotor] = -30;
	  motor[rightMotor] = 30;
	  wait1Msec(600);
	  motor[leftMotor] = 0;
	  motor[rightMotor] = 0;
	for (int i = -127; i<127 ; i +=10){
		potmeter_value = SensorValue(Potmeter_sensor);
		if (potmeter_value < 0 || potmeter_value > 4095){
			break;
		}
  	ServoMove(i); //move to i
  	light_value = SensorValue(Light_sensor); //get the light value
  	potmeter_value = SensorValue(Potmeter_sensor);
  	if (light_value < min){
  		min = light_value; //update the value
  		position = i; //update the light position
  		pot = potmeter_value;
   }

		//writeDebugStreamLine("potmeter = %d",potmeter_value);
 }
	ServoMove(position); //move to position
	wait1Msec(200);
	if(pot <1700){
		motor[leftMotor] = -50;
	  motor[rightMotor] = 0;
	  wait1Msec(600);
	  motor[leftMotor] = 0;
	  motor[rightMotor] = 0;
	  distance += 1;
	}
	else if(pot > 2000){
		motor[leftMotor] = 0;
	  motor[rightMotor] = 50;
	  wait1Msec(600);
	  motor[leftMotor] = 0;
	  motor[rightMotor] = 0;
}
else{}
	//writeDebugStreamLine("potmeter = %d",pot);
	wait1Msec(2000); //wait 5 sec
encoder_value = SensorValue(QuadEncoder);
distance += ((float)encoder_value/320)* 6.9 * 3.14;
writeDebugStreamLine("Quad encoder value = %d\n", distance);
sensor_value = SensorValue(sonarSensor);
if (sensor_value<500){
	while(distance>0){
			SensorValue[QuadEncoder] = 0;
			motor[leftMotor] = 30;
	  	motor[rightMotor] = -30;
	  	wait1Msec(800);
	  	encoder_value = SensorValue(QuadEncoder);
	  	distance = distance + ((float)encoder_value/320) * 6.9 * 3.14;
	  	writeDebugStreamLine("distance = %d\n", distance);
	}
	break;
	}
}
}

void ServoMove(int servoPosition){

  //writeDebugStreamLine("Servo Position = %d",servoPosition);
  motor[Servo] = servoPosition;
  wait1Msec(200);
}
