#include "events/activations/logicals/and.h"

const std::string AndActivation::classId = Hashable::generateUUID();

AndActivation::AndActivation(EventActivation operandA, EventActivation operandB)
    : LogicalActivation<2>(classId, {operandA, operandB}){};

const bool AndActivation::operation(std::array<bool, 2> operands) {
  return operands[0] && operands[1];
};