#pragma once
#include "events/activations/logical.h"

class XorActivation : public LogicalActivation<2> {
private:
  static const std::string classId;

protected:
  const bool operation(std::array<bool, 2> operands) override;

public:
  XorActivation(EventActivation operandA, EventActivation operandB);
  const bool operator==(const XorActivation other) const;
};