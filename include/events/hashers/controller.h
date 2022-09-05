#pragma once

#include "events/hashable.h"
#include "pros/misc.hpp"
#include <cstddef>

template <> std::size_t Hashable::multiVarHash<long, long>(long a, long b);

template <> struct std::hash<pros::Controller> {
  std::size_t operator()(pros::Controller controller) const;
};