#include "events/activation.h"
#include "pros/misc.h"
#include "pros/misc.hpp"

class PressedActivation : public EventActivation {
private:
  pros::Controller *controller;
  pros::controller_digital_e_t button;

public:
  bool test() const override;

  PressedActivation(pros::Controller *inputController,
                    pros::controller_digital_e_t button);
};