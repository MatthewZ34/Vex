#include "main.h"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/misc.h"

#include "pros/rtos.hpp"
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {



}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
 

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);


	//rotat.reset();
	pros::delay(300);

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

	
	//intakeMotor1.move_relative(295, 
	//120);
	//intakeMotor2.move_relative(-295, 
	//120);
		//pros::delay(5000);

//	setDrive(20,-20);

	//setWinch(1600)


// translate(time(ms),power)
//rotate(unitstime, power, postive goes right during turning.)


	//go back into the roller
	// intakeMotor1.move_relative(295, 120);

	// rolley roller

	//rotate(90,1);
	//translate(5500, 50);

	//setWinch(2510);











	//end:

}



/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
int intake = 0;
bool intaketoggle = false;
bool shoottoggle = false;
bool expanded = false;
bool winchdown = false;
float counter =0;
bool inNormal=false;

bool intakeallowed= false;
void opcontrol() {

	while(true){

		setDriveMotors();

		// Turns intake on

		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
			if(intaketoggle == false){
				intakeMotorBot = 127;
			}
			else{
				intakeMotorBot =0;	
			}


			intaketoggle = !intaketoggle;
			inNormal= true;
		}
		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
			if(intaketoggle == false ||inNormal == true){
				intakeMotorBot = -127;
			
			}
			else{
				intakeMotorBot =0;	
			}
			inNormal=false;
			
			intaketoggle = !intaketoggle;
		}
				
		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){
			if(intaketoggle == false){
				intakeMotorBot = 127;
				intakeMotorTop = 127;
			}
			else{
				intakeMotorBot =0;	
				intakeMotorTop = 0;
			}


			intaketoggle = !intaketoggle;
		}
		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)){

			expanded = !expanded;
			walling.set_value(expanded);

		}

		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
			if(intaketoggle == false){
				intakeMotorBot = -127;
				intakeMotorTop = -127;
			}
			else{
				intakeMotorBot =0;	
				intakeMotorTop = 0;
			}
			intaketoggle = !intaketoggle;



		}
		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){
			if(shoottoggle == false){
				Flywheel1 = 127;
				Flywheel2 = 127;
			}
			else{
				Flywheel1 = 0;
				Flywheel2 = 0;
			}


			shoottoggle = !shoottoggle;
		}
		
		// Reverses Intake

		// Winding the Winch backwards



		// Shooting the winch




		pros::delay(20);

	}
}