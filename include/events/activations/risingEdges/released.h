#pragma once

#include "events/activations/risingEdge.h"
#include "pros/misc.h"
#include "pros/misc.hpp"

class NewReleasedActivation : public RisingEdgeActivation<bool> {
private:
  static const std::string classId;
  pros::Controller controller;
  pros::controller_digital_e_t button;

protected:
  const bool getVar() override;

public:
  NewReleasedActivation(pros::Controller controller,
                        pros::controller_digital_e_t button);

  const bool operator==(const NewReleasedActivation) const;
};