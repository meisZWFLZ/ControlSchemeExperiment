#include "events/activations/equals.h"

template <typename V> bool EqualsActivation<V>::test() {
  return val == getVar();
};