#include "events/hashable.h"
// #include <cstddef>
// #include <iterator>
#include <random>
#include <sstream>

// int Hashable::iteration = 0;

std::size_t Hashable::hash() const { return hasher(); };

std::size_t Hashable::Hasher::operator()(const Hashable &hashable) const {
  return hashable.hash();
}

std::size_t std::hash<Hashable>::operator()(const Hashable &hashable) const {
  return hashable.hash();
}

namespace uuid {
static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> dis(0, 15);
static std::uniform_int_distribution<> dis2(8, 11);

std::string generate_uuid_v4() {
  std::stringstream ss;
  int i;
  ss << std::hex;
  for (i = 0; i < 8; i++) {
    ss << dis(gen);
  }
  ss << "-";
  for (i = 0; i < 4; i++) {
    ss << dis(gen);
  }
  ss << "-4";
  for (i = 0; i < 3; i++) {
    ss << dis(gen);
  }
  ss << "-";
  ss << dis2(gen);
  for (i = 0; i < 3; i++) {
    ss << dis(gen);
  }
  ss << "-";
  for (i = 0; i < 12; i++) {
    ss << dis(gen);
  };
  return ss.str();
}
} // namespace uuid

std::string Hashable::generateUUID() { return generateUUID(); };