#pragma once

#include "events/activations/risingEdge.h"
#include "pros/misc.h"
#include "pros/misc.hpp"

class NewPressedActivation : public RisingEdgeActivation<bool> {
private:
  static const std::string classId;
  pros::Controller controller;
  pros::controller_digital_e_t button;

protected:
  const bool getVar() override;

public:
  NewPressedActivation(pros::Controller controller,
                       pros::controller_digital_e_t button);

  const bool operator==(const NewPressedActivation) const;
};