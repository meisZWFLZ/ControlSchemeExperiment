#include "listener.h"
#include <map>
#include <unordered_map>
#include <vector>


class EventHandler {
private:
  static std::unordered_map<const EventActivation &, std::vector<EventListener>>
      listenerMap;
  static bool setUp; // is manager set up (is event loop running)

  static void managerLoop();
  static void setUpManager();

public:
  static void addListener(const EventListener &listener);
};