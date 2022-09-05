#include "events/handler.h"
#include "pros/rtos.hpp"
#include <chrono>

bool EventHandler::setUp = false;
std::unordered_map<EventActivation, std::vector<EventAction>, Hashable::Hasher>
    EventHandler::listenerMap = {};

void EventHandler::addListener(EventActivation activation, EventAction action) {
  if (!EventHandler::setUp)
    EventHandler::setUpManager();
  /* std::vector<EventAction> val =  */
  EventHandler::listenerMap.at(activation).push_back(action);
  action.execute();
  // if (val.empty())
  //   val = {};
  // val.push_back(action);
  // EventHandler::listenerMap[activation] ;
};

// void EventHandler::addListener(myKey key, myVal val) {
//   EventHandler::listenerMap[key].push_back(val);
// };

void EventHandler::managerLoop() {
  // std::unordered_map<const EventActivation&,
  // std::vector<EventListener>>::iterator i;
  // std::vector<EventListener>::iterator j;
  while (1) {
    for (auto i = EventHandler::listenerMap.begin(); i != listenerMap.end();
         ++i)
      if (true)
        for (auto j = i->second.begin(); j != i->second.end(); ++j)
          j->execute();
    pros::delay(25);
  }
}

void EventHandler::setUpManager() {
  setUp = true;
  pros::Task::create(managerLoop);
};

