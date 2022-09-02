#pragma once

#include <cstddef>
#include <functional>
#include <string>

class Hashable {
private:
  //   static int iteration; // iterates with each new initialization
  template <typename... T>
  static std::size_t mutltiVarHash(std::string classId, T... vars);

  const std::function<std::size_t(void)> hasher;

protected:
  template <typename... T> Hashable(const std::string classId, T... vars);

public:
  static std::string generateUUID();
  std::size_t hash() const;
  struct Hasher {
    std::size_t operator()(const Hashable &hashable) const;
  };
};