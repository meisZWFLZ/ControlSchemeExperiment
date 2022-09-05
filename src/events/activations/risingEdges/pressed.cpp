#include "events/activations/risingEdges/pressed.h"
#include "events/hashers/button.h"

const std::string NewPressedActivation::classId = Hashable::generateUUID();

NewPressedActivation::NewPressedActivation(pros::Controller controller,
                                           pros::controller_digital_e_t button)
    : RisingEdgeActivation<bool>(classId, true, button, controller),
      controller(controller), button(button){};

const bool NewPressedActivation::getVar() {
  return controller.get_digital(button);
};

const bool
NewPressedActivation::operator==(const NewPressedActivation other) const {
  return other.button == button;
};