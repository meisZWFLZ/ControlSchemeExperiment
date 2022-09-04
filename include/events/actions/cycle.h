#pragma once

#include "events/action.h"
#include <array>
#include <atomic>

template <int NumOfChildren> class CycleAction : public EventAction {
private:
  std::array<EventAction, NumOfChildren> children;
  std::atomic<int> i = 0;

public:
  CycleAction(std::array<EventAction, NumOfChildren> children);
  void execute() override;
};

template <int NumOfChildren>
CycleAction<NumOfChildren>::CycleAction(
    std::array<EventAction, NumOfChildren> children)
    : children(children) {}

template <int NumOfChildren> void CycleAction<NumOfChildren>::execute() {
  if (i == NumOfChildren)
    i = 0;
  children[i++].execute();
}