#pragma once

#include "events/hashable.h"
#include "events/hashers/controller.h"
#include "pros/misc.hpp"
#include <cstddef>

template <>
std::size_t Hashable::multiVarHash(std::string classId, bool val,
                                   pros::controller_digital_e_t button,
                                   pros::Controller controller);