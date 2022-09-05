#include "events/hashers/button.h"

template <>
std::size_t Hashable::multiVarHash(std::string classId, bool val,
                                   pros::controller_digital_e_t button,
                                   pros::Controller controller) {
  // Compute individual hash values for first, second and third
  // http://stackoverflow.com/a/1646913/126995
  size_t res = 17;
  res = res * 31 + std::hash<std::string>()(classId);
  res = res * 31 + std::hash<bool>()(val);
  res = res * 31 + std::hash<pros::controller_digital_e_t>()(button);
  res = res * 31 + std::hash<pros::Controller>()(controller);
  return res;
};