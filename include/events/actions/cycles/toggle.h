#pragma once

#include "events/actions/cycle.h"

class ToggleAction : public CycleAction<2> {
public:
  ToggleAction(EventAction action1, EventAction action2);
};