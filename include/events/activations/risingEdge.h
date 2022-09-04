#pragma once

#include "events/activation.h"

template <typename V> class RisingEdgeActivation : EventActivation {
private:
  const V val;

  // true -> last getVar == val
  // false -> last getVar != val
  bool lastTest;

protected:
  const virtual V getVar();
  template <typename... T>
  RisingEdgeActivation<V>(std::string classId, const V val, T... vars);

public:
  bool test() override;
};
template <typename V> bool RisingEdgeActivation<V>::test() {
  if (val == getVar()) {
    if (lastTest)
      return false;
    else
      return lastTest = true;
  } else
    return lastTest = false;
}

template <typename V>
template <typename... T>
RisingEdgeActivation<V>::RisingEdgeActivation(std::string classId, const V val,
                                              T... vars)
    : val(val), EventActivation(classId, val, vars...){};