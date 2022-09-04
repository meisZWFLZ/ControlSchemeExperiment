#include "events/actions/cycles/toggle.h"

ToggleAction::ToggleAction(EventAction action1, EventAction action2)
    : CycleAction<2>({action1, action2}){};