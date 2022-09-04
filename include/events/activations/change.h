#pragma once

#include "events/activation.h"
template <typename V> class ChangeActivation : public EventActivation {
private:
  V lastVal;

protected:
  virtual V getVal() = 0;
  template <typename... T> inline ChangeActivation<V>(std::string classId, T... vars);

public:
  bool test() override;
};

template <typename V>
template <typename... T>
ChangeActivation<V>::ChangeActivation(std::string classId, T... vars)
    : EventActivation(classId, vars...){};