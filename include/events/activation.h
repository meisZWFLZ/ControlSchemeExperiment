#pragma once

#include "hashable.h"
#include <string>

class EventActivation : public Hashable {
  // private:
  //   static const std::string classId;

protected:
  template <typename... T> EventActivation(std::string classId, T... vars);

public:
  // EventActivation();

  virtual const bool operator==(const EventActivation other) const;
  virtual bool test();

  virtual ~EventActivation();
};