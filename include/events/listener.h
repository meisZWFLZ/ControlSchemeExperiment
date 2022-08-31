#include "activation.h"
#include "pros/adi.hpp"
// #include <functional>

class EventAction {};

class EventListener {
public:
  EventActivation activation;
  virtual void listener();
};
