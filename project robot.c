#pragma config(Sensor, S1,     button,         sensorEV3_Touch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


task main()
{
	int time;
	time = 2000;
	int speedleft;
	speedleft = 10;
	int speedright;
	speedright = 20;
	int mode = 1;
	while(true)
	{
		if(mode== 1)
		{
			motor(motorB)= speedleft;
			motor(motorA)= speedright;
			wait1Msec(4000);
			speedright=speedright + 10;
			speedleft=speedleft + 10;
		if(SensorValue(button) == 1)
			{
			resetMotorEncoder(motorA);
			mode = 2;
			}
		}
		if(SensorValue(button) == 1)
		{
			mode = 2;
		}
		if(mode ==2)
		{
			if(SensorValue(button)==1)
			{
			  motor(motorB)= -80;
			  motor(motorA)= -50;
			  wait1Msec(3000);
			  motor(motorA)= 80;
			  motor(motorB)= 100;
				wait1Msec(1500);
				if(getMotorEncoder(motorA) > 6000)
			  {
				  motor(motorA)= -100;
				  motor(motorB)= 100;
			  	motor(motorA)= 100;
				  motor(motorB)= 100;
				  wait1Msec(4000);
				  speedleft = 10;
				  speedright = 20;
				  mode = 1;
			  }
		  }
		}
	}
}
