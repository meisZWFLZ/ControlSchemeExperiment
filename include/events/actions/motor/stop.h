#pragma once

#include "events/action.h"
#include "pros/motors.hpp"
#include <vector>

class MotorStopAction : public EventAction {
private:
  pros::Motor motor;

public:
  MotorStopAction(pros::Motor motor);
  void execute() override;
};