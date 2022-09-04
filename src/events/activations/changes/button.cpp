#include "events/activations/changes/button.h"
#include "events/hashable.h"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include <functional>
#include <string>
const std::string ButtonChangeActivation::classId = Hashable::generateUUID();

ButtonChangeActivation::ButtonChangeActivation(
    pros::controller_digital_e_t button, pros::Controller controller)
    : button(button),
      controller(controller), ChangeActivation<bool>(classId, button,
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

template <> std::size_t Hashable::multiVarHash<long, long>(long a, long b) {
  size_t res = 17;
  res = res * 31 + std::hash<long>()(a); 
  res = res * 31 + std::hash<long>()(b);
  return res;
};

namespace std {
template <> struct hash<pros::Controller> {
  std::size_t operator()(pros::Controller controller) const {
    ;
    return Hashable::multiVarHash(controller.get_battery_capacity(),
                                  controller.get_battery_level());
  }
};
} // namespace std

template <>
std::size_t
Hashable::multiVarHash<std::string, pros::controller_digital_e_t,
                       pros::Controller>(std::string classId,
                                         pros::controller_digital_e_t button,
                                         pros::Controller controller) {
  using std::hash;
  // Compute individual hash values for first, second and third
  // http://stackoverflow.com/a/1646913/126995
  size_t res = 17;
  res = res * 31 + hash<std::string>()(classId);
  res = res * 31 + hash<pros::controller_digital_e_t>()(button);
  res = res * 31 + hash<pros::Controller>()(controller);
  return res;
}

template <>
Hashable::Hashable(std::string classId, pros::controller_digital_e_t button,
                   pros::Controller controller)
    : hasher(std::bind(multiVarHash<std::string, pros::controller_digital_e_t,
                                    pros::Controller>,
                       classId, button, controller)) {}
// template<>
// template<>
// ChangeActivation<bool>::ChangeActivation(std::string classId,
// pros::controller_digital_e_t button, pros::Controller) {};