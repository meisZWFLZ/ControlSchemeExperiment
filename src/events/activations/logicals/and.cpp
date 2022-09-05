#include "events/activations/logicals/and.h"

const std::string AndActivation::classId = Hashable::generateUUID();

AndActivation::AndActivation(EventActivation operandA, EventActivation operandB)
    : LogicalActivation<2>(classId, {operandA, operandB}){};

const bool AndActivation::operation(std::array<bool, 2> operands) {
  return operands[0] && operands[1];
};

const bool AndActivation::operator==(const AndActivation other) const {
  return other.children[0] == children[0] && other.children[1] == children[1];
};