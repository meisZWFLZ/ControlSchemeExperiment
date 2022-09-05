#include "events/activations/logicals/xnor.h"

const std::string XnorActivation::classId = Hashable::generateUUID();

XnorActivation::XnorActivation(EventActivation operandA,
                               EventActivation operandB)
    : LogicalActivation<2>(classId, {operandA, operandB}){};

const bool XnorActivation::operation(std::array<bool, 2> operands) {
  return !(operands[0] ^ operands[1]);
};
const bool XnorActivation::operator==(const XnorActivation other) const {
  return other.children[0] == children[0] && other.children[1] == children[1];
};