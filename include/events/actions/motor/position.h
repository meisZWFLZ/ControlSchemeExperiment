#pragma once

#include "events/action.h"
#include "pros/motors.hpp"
#include <vector>

class MotorPositionAction : public EventAction {
private:
  pros::Motor motor;

protected:
  virtual const std::int32_t getPosition();
  virtual const std::int32_t getVelocity();

public:
  MotorPositionAction(pros::Motor motor);
  void execute() override;

  class Value;
};

class MotorPositionAction::Value : public MotorPositionAction {
protected:
  const std::int32_t position;
  const std::int32_t velocity;
  const std::int32_t getPosition() override;
  const std::int32_t getVelocity() override;

public:
  Value(pros::Motor motor, const std::int32_t position,
        const std::int32_t velocity);
};