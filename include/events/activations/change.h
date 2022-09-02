#pragma once

#include "events/activation.h"
template <typename V> class ChangeActivation : public EventActivation {
private:
  V lastVal;

protected:
  virtual V getVal() = 0;
  template <typename... T> ChangeActivation<V>(std::string classId, T... vars);

public:
  bool test() override;
};