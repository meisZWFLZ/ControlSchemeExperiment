#include "events/activations/changes/axis.h"
#include "events/hashers/controller.h"

const std::string AxisChangeActivation::classId = Hashable::generateUUID();

AxisChangeActivation::AxisChangeActivation(pros::controller_analog_e_t axis,
                                           pros::Controller controller)
    : axis(axis), controller(controller), ChangeActivation<std::int32_t>(
                                              classId, axis, controller){};

std::int32_t AxisChangeActivation::getVal() { return controller.get_analog(axis); };

const bool
AxisChangeActivation::operator==(const AxisChangeActivation other) const {
  return other.axis == axis;
}

template <> bool ChangeActivation<std::int32_t>::test() {
  bool currentVal = this->getVal();
  if (lastVal != currentVal) {
    lastVal = currentVal;
    return true;
  }
  return false;
};

template <>
std::size_t
Hashable::multiVarHash<std::string, pros::controller_analog_e_t,
                       pros::Controller>(std::string classId,
                                         pros::controller_analog_e_t axis,
                                         pros::Controller controller) {
  using std::hash;
  // Compute individual hash values for first, second and third
  // http://stackoverflow.com/a/1646913/126995
  size_t res = 17;
  res = res * 31 + hash<std::string>()(classId);
  res = res * 31 + hash<pros::controller_analog_e_t>()(axis);
  res = res * 31 + hash<pros::Controller>()(controller);
  return res;
}

template <>
Hashable::Hashable(std::string classId, pros::controller_analog_e_t axis,
                   pros::Controller controller)
    : hasher(std::bind(multiVarHash<std::string, pros::controller_analog_e_t,
                                    pros::Controller>,
                       classId, axis, controller)) {}
// template<>
// template<>
// ChangeActivation<bool>::ChangeActivation(std::string classId,
// pros::controller_digital_e_t button, pros::Controller) {};