#include "events/activations/logicals/xor.h"

const std::string XorActivation::classId = Hashable::generateUUID();

XorActivation::XorActivation(EventActivation operandA, EventActivation operandB)
    : LogicalActivation<2>(classId, {operandA, operandB}){};

const bool XorActivation::operation(std::array<bool, 2> operands) {
  return operands[0] ^ operands[1];
};

const bool XorActivation::operator==(const XorActivation other) const {
  return other.children[0] == children[0] && other.children[1] == children[1];
};