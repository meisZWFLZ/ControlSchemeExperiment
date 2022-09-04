#include "events/activations/logicals/not.h"

const std::string NotActivation::classId = Hashable::generateUUID();

NotActivation::NotActivation(EventActivation operand)
    : LogicalActivation<1>(classId, {operand}){};

const bool NotActivation::operation(std::array<bool, 1> operands) {
  return !operands[0];
};