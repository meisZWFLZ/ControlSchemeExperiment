#include "events/activation.h"
template <typename V> class ChangeActivation : public EventActivation {
private:
  V lastVal;

protected:
  virtual V getVal();

public:
  bool test() const override;
};