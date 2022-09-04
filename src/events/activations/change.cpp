#include "events/activations/change.h"
#include "pros/misc.h"
#include "pros/misc.hpp"

template <typename V> bool ChangeActivation<V>::test() {
  V currentVal = getVal();
  if (lastVal != currentVal) {
    lastVal = currentVal;
    return true;
  }
  return false;
};

// template <typename V>
// template <typename... T>
// ChangeActivation<V>::ChangeActivation(std::string classId, T... vars)
//     : EventActivation(classId, vars...){};
