#include "events/activations/logicals/nand.h"

const std::string NandActivation::classId = Hashable::generateUUID();

NandActivation::NandActivation(EventActivation operandA,
                               EventActivation operandB)
    : LogicalActivation<2>(classId, {operandA, operandB}){};

const bool NandActivation::operation(std::array<bool, 2> operands) {
  return !(operands[0] && operands[1]);
};

const bool NandActivation::operator==(const NandActivation other) const {
  return other.children[0] == children[0] && other.children[1] == children[1];
};