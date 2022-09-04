#include "events/activations/logicals/nor.h"

const std::string NorActivation::classId = Hashable::generateUUID();

NorActivation::NorActivation(EventActivation operandA, EventActivation operandB)
    : LogicalActivation<2>(classId, {operandA, operandB}){};

const bool NorActivation::operation(std::array<bool, 2> operands) {
  return !(operands[0] || operands[1]);
};