#pragma once

#include <cstddef>
#include <functional>
#include <string>

class Hashable {
private:
  const std::function<std::size_t(void)> hasher;

protected:
  template <typename... T>
  inline Hashable(const std::string classId, T... vars);

public:
  template <typename... T> static inline std::size_t multiVarHash(T... vars);

  static std::string generateUUID();
  std::size_t hash() const;
  struct Hasher {
    std::size_t operator()(const Hashable &hashable) const;
  };
};

template <typename... T> std::size_t Hashable::multiVarHash(T... vars) {
  using std::hash;
  // Compute individual hash values for first, second and third
  // http://stackoverflow.com/a/1646913/126995
  size_t res = 17;
  res = res * 31 + hash<T...>()(vars...);
  return res;
};

template <typename... T>
Hashable::Hashable(const std::string classId, T... vars)
    : hasher(std::bind(multiVarHash<std::string, T...>, classId, vars...)){};



template <> struct std::hash<Hashable> {
  std::size_t operator()(const Hashable &hashable) const;
};