#pragma once

#include "events/action.h"
#include "pros/motors.hpp"
#include <vector>

class MotorVelocityAction : public EventAction {
private:
  pros::Motor motor;

protected:
  virtual const std::int32_t getVelocity();

public:
  MotorVelocityAction(pros::Motor motor);
  void execute() override;

  class Value;
};

class MotorVelocityAction::Value : public MotorVelocityAction {
protected:
  const std::int32_t velocity;
  const std::int32_t getVelocity() override;

public:
  Value(pros::Motor motor,
                                    const std::int32_t velocity);
};
