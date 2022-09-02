#include "events/activations/change.h"
#pragma once

#include "pros/misc.h"
#include "pros/misc.hpp"

class ButtonChangeActivation : public ChangeActivation<bool> {
private:
  static const std::string classId;

protected:
  bool getVal() override;

public:
  pros::controller_digital_e_t button;
  pros::Controller controller;

  ButtonChangeActivation(pros::controller_digital_e_t button,
                          pros::Controller controller);

  const bool operator==(const ButtonChangeActivation other) const;
};