#pragma once

#include "events/action.h"
#include "pros/motors.hpp"
#include <vector>

class MotorVoltageAction : public EventAction {
private:
  pros::Motor motor;

protected:
  virtual const std::int32_t getVoltage();

public:
  MotorVoltageAction(pros::Motor motor);
  void execute() override;

  class Value;
};

class MotorVoltageAction::Value : public MotorVoltageAction {
protected:
  const std::int32_t voltage;
  const std::int32_t getVoltage() override;

public:
  Value(pros::Motor motor, const std::int32_t voltage);
};