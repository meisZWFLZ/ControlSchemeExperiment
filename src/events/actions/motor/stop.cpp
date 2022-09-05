#include "events/actions/motor/stop.h"
#include "pros/motors.hpp"

MotorStopAction::MotorStopAction(pros::Motor motor) : motor(motor){};

void MotorStopAction::execute() { motor.brake(); };