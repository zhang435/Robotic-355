/**************************************************************************
*           MAIN1
*  Pauses for 2 seconds then prints 'Hello World' to the debug stream
*  to display the debug stream:
*      -download the program to the cortex
*      -in the Robot menu select debugger
*      -go back to Robot; then go to the debugger window and select debug stream
*
***************************************************************************/

int hailstone(int n){
//return the next number
	if(n == 1)
		return 1;
	if(n%2 == 0)
		return n/2;
	return 3*n + 1;
}

task main()
{
  wait1Msec(2000);
  //writeDebugStream("Hello World");
	int n = 7;
  while(true){
 	writeDebugStream("%d",n);//print the number
 	writeDebugStream(" ");
  if(n == 1)
  	return;//stop when the int is 1
 	n = hailstone(n);//update the number

	}
}
