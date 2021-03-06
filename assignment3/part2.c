#pragma config(Sensor, in1,    Light_sensor,   sensorReflection)
#pragma config(Motor,  port2,           Servo,         tmotorServoContinuousRotation, openLoop)
#pragma config(Sensor, in2,    Potmeter_sensor,     sensorPotentiometer)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void ServoMove(int servoPosition);

task main()
{
	int	light_value;
	int	potmeter_value;
	int min = 1024; //maxmum the light value
	int position = -127; // initial the position
	for (int i = -127; i<127 ; i +=15){
		potmeter_value = SensorValue(Potmeter_sensor);
		if (potmeter_value < 0 || potmeter_value > 4095){
			break;
		}
  	ServoMove(i); //move to i
  	light_value = SensorValue(Light_sensor); //get the light value
  	if (light_value < min){
  		min = light_value; //update the value
  		position = i; //update the light position
   }
		potmeter_value = SensorValue(Potmeter_sensor);
		writeDebugStreamLine("potmeter = %d",potmeter_value);
 }
	ServoMove(position); //move to position
	potmeter_value = SensorValue(Potmeter_sensor);
	writeDebugStreamLine("potmeter = %d",potmeter_value);
	wait1Msec(5000); //wait 1 sec
	
}

void ServoMove(int servoPosition){

  writeDebugStreamLine("Servo Position = %d",servoPosition);
  motor[Servo] = servoPosition;
  wait1Msec(1000);
}
