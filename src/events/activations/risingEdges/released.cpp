#include "events/activations/risingEdges/released.h"
#include "events/hashers/button.h"

const std::string NewReleasedActivation::classId = Hashable::generateUUID();

NewReleasedActivation::NewReleasedActivation(
    pros::Controller controller, pros::controller_digital_e_t button)
    : RisingEdgeActivation<bool>(classId, false, button, controller),
      controller(controller), button(button){};

const bool NewReleasedActivation::getVar() {
  return controller.get_digital(button);
};

const bool
NewReleasedActivation::operator==(const NewReleasedActivation other) const {
  return other.button == button;
};