#include "events/actions/motor/position.h"
#include "pros/motors.hpp"

MotorPositionAction::MotorPositionAction(pros::Motor motor) : motor(motor){};

void MotorPositionAction::execute() {
  motor.move_absolute(getPosition(), getVelocity());
};

MotorPositionAction::Value::Value(pros::Motor motor,
                                  const std::int32_t position,
                                  const std::int32_t velocity)
    : MotorPositionAction(motor), position(position), velocity(velocity){};

const std::int32_t MotorPositionAction::Value::getPosition() {
  return position;
}

const std::int32_t MotorPositionAction::Value::getVelocity() {
  return velocity;
}