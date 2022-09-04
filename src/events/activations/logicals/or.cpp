#include "events/activations/logicals/or.h"

const std::string OrActivation::classId = Hashable::generateUUID();

OrActivation::OrActivation(EventActivation operandA, EventActivation operandB)
    : LogicalActivation<2>(classId, {operandA, operandB}){};

const bool OrActivation::operation(std::array<bool, 2> operands) {
  return operands[0] || operands[1];
};