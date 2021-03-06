#pragma config(Motor,  port2,           RightDriveMotor, tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port5,           ClawMotor,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           ArmMotor,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          LeftDriveMotor, tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	// ..........................................................................
	// Insert user code here.
	// ..........................................................................

	// Remove this function call once you have "real" code.
	AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol() //Task User control
{
	// User control code here, inside the loop

	while (true) {
		motor[LeftDriveMotor] = vexRT[Ch3];
		motor[RightDriveMotor] = vexRT[Ch2];

		if (vexRT[Btn5UXmtr2] == 1) //Claw opens
			motor[ClawMotor] = 127;
		else if (vexRT[Btn5DXmtr2] == 1) //Claw Closes
			motor[ClawMotor] = -127;
		else //Claw stays where it is
			motor[ClawMotor] = 0;

		if (vexRT[Btn6UXmtr2] == 1) //Arm goes up
			motor[ArmMotor] = 127;
		else if (vexRT[Btn6DXmtr2] == 1) //Arm goes down
			motor[ArmMotor] = -127;
		else //Arm stays where it is
			motor[ArmMotor] = 0;
	}
}
