#include "events/handler.hpp"
#include "pros/rtos.hpp"
#include <chrono>
#include <vector>

bool EventHandler::setUp = false;

void EventHandler::addListener(const EventListener &listener) {
  if (!EventHandler::setUp)
    EventHandler::setUpManager();
  EventHandler::listenerMap.at(listener.activation).push_back(listener);
};

void EventHandler::managerLoop() {
  std::unordered_map<const EventActivation&, std::vector<EventListener>>::iterator i;
  std::vector<EventListener>::iterator j;
  while (1) {
    for (i = EventHandler::listenerMap.begin(); i != listenerMap.end(); ++i)
      if (i->first.test())
        for (j = i->second.begin(); j != i->second.end(); ++j)
          j->listener();
    pros::delay(50);
  }
}

void EventHandler::setUpManager() {
  setUp = true;
  pros::Task::create(managerLoop);
};