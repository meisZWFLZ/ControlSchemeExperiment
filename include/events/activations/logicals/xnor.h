#pragma once
#include "events/activations/logical.h"

class XnorActivation : public LogicalActivation<2> {
private:
  static const std::string classId;

protected:
  const bool operation(std::array<bool, 2> operands) override;

public:
  XnorActivation(EventActivation operandA, EventActivation operandB);
};