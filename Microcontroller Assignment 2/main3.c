#pragma config(Motor,  port1,           rightMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393, openLoop)
#pragma config(Sensor, dgtl9,  sonarSensor,    sensorSONAR_mm)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#pragma config(Sensor, in1,    lightSensor,    sensorReflection)
//#pragma config(Sensor, dgtl9,  sonarSensor,         sensorSONAR_mm) 


//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*******************************************************************************
*
*  This file is meant as an introduction and as a template for developing
*  programs to run on the Vex controller.
*
*******************************************************************************/

/*******************************************************************************
*
*	main
*
*******************************************************************************/
task main()
{
//  int bumper = 1;	              // normal bumper state = 1; when pressed = 0

  wait1Msec(2000);    					// give stuff time to turn on
	short sensor_value;
  while(true)
  {
    //Joystick control of the motors
        // up = CCW
		wait1Msec(200);
    //If the bumper is press, automatically backup
		//sensor_value = SensorValue(lightSensor);
		//motor[leftMotor] = 127 - (127/(float)1023)*sensor_value;
		//motor[rightMotor] = -127 + (127/(float)1023)*sensor_value;
		//writeDebugStream("%d\n",(127/1023) * (float)sensor_value);
		//writeDebugStream("light sensero : %d   motor speed : %d \n",sensor_value,127 - (127/1023)*sensor_value);//print the number
		motor[leftMotor] = 127; //fullspeed backwards
	  motor[rightMotor] = -127;
		sensor_value = SensorValue(sonarSensor); 
		writeDebugStream("%d\n",sensor_value);
		if (sensor_value > 0 && sensor_value < 500){
			motor[leftMotor]  = 0;  //stop motors
	    motor[rightMotor] = 0;  //stop motors
	    wait1Msec(200);
			motor[leftMotor] = -127; //fullspeed backwards
	    motor[rightMotor] = -127; //fullspeed backwards
	      // keep backing up for 1000ms (1 sec)
	    wait1Msec(500);
		}
  }
}