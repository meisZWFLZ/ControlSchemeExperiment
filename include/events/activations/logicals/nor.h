#pragma once
#include "events/activations/logical.h"

class NorActivation : public LogicalActivation<2> {
private:
  static const std::string classId;

protected:
  const bool operation(std::array<bool, 2> operands) override;

public:
  NorActivation(EventActivation operandA, EventActivation operandB);
  const bool operator==(const NorActivation other) const;
};