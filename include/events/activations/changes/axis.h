#pragma once

#include "events/activations/change.h"
#include "pros/misc.hpp"

class AxisChangeActivation : ChangeActivation<std::int32_t> {
private:
  static const std::string classId;

protected:
  std::int32_t getVal() override;

public:
  pros::controller_analog_e_t axis;
  pros::Controller controller;

  AxisChangeActivation(pros::controller_analog_e_t axis,
                         pros::Controller controller);

  const bool operator==(const AxisChangeActivation other) const;
};