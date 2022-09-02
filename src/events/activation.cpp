#include "events/activation.h"

// const bool EventActivation::operator==(const EventActivation other) const {
//   return this->uuid == other.uuid;
// };

template <typename... T>
EventActivation::EventActivation(std::string classId, T... vars)
    : Hashable(classId, vars...){};

bool EventActivation::test() { return false; };

const bool EventActivation::operator==(const EventActivation other) const {
  return false;
};

EventActivation::~EventActivation() {}