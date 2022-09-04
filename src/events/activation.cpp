#include "events/activation.h"

// const bool EventActivation::operator==(const EventActivation other) const {
//   return this->uuid == other.uuid;
// };



bool EventActivation::test() { return false; };

const bool EventActivation::operator==(const EventActivation other) const {
  return false;
};

EventActivation::~EventActivation() {}