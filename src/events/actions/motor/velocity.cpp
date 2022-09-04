#include "events/actions/motor/velocity.h"
#include "pros/motors.hpp"

MotorVelocityAction::MotorVelocityAction(pros::Motor motor) : motor(motor){};

void MotorVelocityAction::execute() { motor.move_velocity(getVelocity()); };

MotorVelocityAction::Value::Value(pros::Motor motor,
                                  const std::int32_t velocity)
    : MotorVelocityAction(motor), velocity(velocity){};

const std::int32_t MotorVelocityAction::Value::getVelocity() {
  return velocity;
}