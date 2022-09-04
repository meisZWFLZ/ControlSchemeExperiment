#pragma once

#include "events/activation.h"

template <int numOfOperands> class LogicalActivation : public EventActivation {
private:
  std::array<EventActivation, numOfOperands> children;

protected:
  virtual const bool operation(std::array<bool, numOfOperands> operands);
  LogicalActivation(const std::string classId,
                    std::array<EventActivation, numOfOperands> children);

public:
  bool test() override;
};