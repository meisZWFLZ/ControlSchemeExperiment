#pragma once

#include "events/action.h"
#include <vector>

class MultiAction : public EventAction {
private:
  std::vector<EventAction> children;

public:
  MultiAction(const std::vector<EventAction> children);
  void execute() override;
};