#include "events/hashers/controller.h"
template <> std::size_t Hashable::multiVarHash<long, long>(long a, long b) {
  size_t res = 17;
  res = res * 31 + std::hash<long>()(a);
  res = res * 31 + std::hash<long>()(b);
  return res;
};

std::size_t
std::hash<pros::Controller>::operator()(pros::Controller controller) const {
  return Hashable::multiVarHash(controller.get_battery_capacity(),
                                controller.get_battery_level());
}
