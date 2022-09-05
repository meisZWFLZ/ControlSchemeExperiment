#pragma once

#include "events/activation.h"

template <int numOfOperands> class LogicalActivation : public EventActivation {
protected:
  virtual const bool operation(std::array<bool, numOfOperands> operands);
  LogicalActivation(const std::string classId,
                    std::array<EventActivation, numOfOperands> children);

public:
  std::array<EventActivation, numOfOperands> children;
  bool test() override;
};