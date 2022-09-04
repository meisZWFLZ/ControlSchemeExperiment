#include "events/actions/motor/voltage.h"
#include "pros/motors.hpp"

MotorVoltageAction::MotorVoltageAction(pros::Motor motor) : motor(motor){};

void MotorVoltageAction::execute() { motor.move_velocity(getVoltage()); };

MotorVoltageAction::Value::Value(pros::Motor motor, const std::int32_t voltage)
    : MotorVoltageAction(motor), voltage(voltage){};

const std::int32_t MotorVoltageAction::Value::getVoltage() { return voltage; }