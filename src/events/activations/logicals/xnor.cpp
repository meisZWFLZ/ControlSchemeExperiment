#include "events/activations/logicals/xnor.h"

const std::string XnorActivation::classId = Hashable::generateUUID();

XnorActivation::XnorActivation(EventActivation operandA,
                               EventActivation operandB)
    : LogicalActivation<2>(classId, {operandA, operandB}){};

const bool XnorActivation::operation(std::array<bool, 2> operands) {
  return !(operands[0] ^ operands[1]);
};