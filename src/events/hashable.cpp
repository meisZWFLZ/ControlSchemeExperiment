#include "events/hashable.h"
#include <cstddef>
#include <iterator>
#include <random>
#include <sstream>

// int Hashable::iteration = 0;

template <typename... T>
Hashable::Hashable(const std::string classId, T... vars) {
  hasher = std::bind(mutltiVarHash, classId, vars...);
};
template <typename... T>
std::size_t Hashable::mutltiVarHash(std::string classId, T... vars) {
  using std::hash;
  // Compute individual hash values for first, second and third
  // http://stackoverflow.com/a/1646913/126995
  size_t res = 17;
  res = res * 31 + hash<std::string>()(classId);
  res = res * 31 + hash<T...>()(vars...);
  return res;
};

std::size_t Hashable::hash() const { return hasher(); };

std::size_t Hashable::Hasher::operator()(const Hashable &hashable) const {
  using std::hash;
  using std::size_t;
  using std::string;

  return hashable.hash();
}

// namespace std {

// template <> struct hash<Hashable> {
//   std::size_t operator()(const Hashable &hashable) const {
//     return hashable.hash();
//   }
// };
// }; // namespace std

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