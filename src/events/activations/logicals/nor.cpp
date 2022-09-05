#include "events/activations/logicals/nor.h"

const std::string NorActivation::classId = Hashable::generateUUID();

NorActivation::NorActivation(EventActivation operandA, EventActivation operandB)
    : LogicalActivation<2>(classId, {operandA, operandB}){};

const bool NorActivation::operation(std::array<bool, 2> operands) {
  return !(operands[0] || operands[1]);
};

const bool NorActivation::operator==(const NorActivation other) const {
  return other.children[0] == children[0] && other.children[1] == children[1];
};