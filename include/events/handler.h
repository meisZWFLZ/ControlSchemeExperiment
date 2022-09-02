#pragma once
#include "activation.h"

#include "action.h"
#include <map>
#include <unordered_map>
#include <vector>

class EventHandler {
private:
  static std::unordered_map<EventActivation, std::vector<EventAction>,
                            Hashable::Hasher>
      listenerMap;
  static bool setUp; // is manager set up (is event loop running)

  static void managerLoop();
  static void setUpManager();

public:
  static void addListener(EventActivation, EventAction);
};