#pragma once

#include "events/activation.h"
template <typename V> class EqualsActivation : public EventActivation {
private:
  const V val;

protected:
  virtual const V getVar() = 0;
  template <typename... T>
  inline EqualsActivation<V>(std::string classId, const V val, T... vars);

public:
  bool test() override;
};

template <typename V>
template <typename... T>
EqualsActivation<V>::EqualsActivation(std::string classId, const V val, T... vars)
    : val(val), EventActivation(classId, vars...){};