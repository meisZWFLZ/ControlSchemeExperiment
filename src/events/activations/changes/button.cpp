#include "events/activations/changes/button.h"
#include "activations/change.h"
#include "hashable.h"
#include "pros/misc.h"
#include "pros/misc.hpp"
const std::string ButtonChangeActivation::classId = Hashable::generateUUID();

ButtonChangeActivation::ButtonChangeActivation(
    pros::controller_digital_e_t button, pros::Controller controller)
    : button(button),
      controller(controller), ChangeActivation(classId, button,
                                                     controller){};

bool ButtonChangeActivation::getVal() {
  return controller.get_digital(button);
};

const bool
ButtonChangeActivation::operator==(const ButtonChangeActivation other) const {
  return other.button == button;
}

template <> bool ChangeActivation<bool>::test() {
  bool currentVal = this->getVal();
  if (lastVal != currentVal) {
    lastVal = currentVal;
    return true;
  }
  return false;
};
// template<>
// template<>
// ChangeActivation<bool>::ChangeActivation(std::string classId, pros::controller_digital_e_t button, pros::Controller) {};