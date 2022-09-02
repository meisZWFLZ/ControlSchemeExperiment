#include "events/activations/change.h"

template <typename V> bool ChangeActivation<V>::test() {
  V currentVal = getVal();
  if (lastVal != currentVal) {
    lastVal = currentVal;
    return true;
  }
  return false;
};

template <typename V>
template <typename... T>
ChangeActivation<V>::ChangeActivation(std::string classId, T... vars)
    : EventActivation(classId, vars...){};

template <>
template <typename... T>
ChangeActivation<bool>::ChangeActivation(std::string classId, T... vars)
    : EventActivation(classId, vars...){};