#include "events/activations/logical.h"
#include "events/activation.h"
#include "events/hashable.h"
#include <string>

template <>
LogicalActivation<1>::LogicalActivation(std::string classId,
                                        std::array<EventActivation, 1> children)
    : EventActivation(classId, children), children(children){};
template <>
LogicalActivation<2>::LogicalActivation(std::string classId,
                                        std::array<EventActivation, 2> children)
    : EventActivation(classId, children), children(children){};

template <int numOfOperands> bool LogicalActivation<numOfOperands>::test() {
  std::array<bool, numOfOperands> operands;
  for (int i = 0; i < numOfOperands; ++i) {
    operands[i] = children[i].test();
  }
  return operation(operands);
}
template <> bool LogicalActivation<1>::test() {
  return operation({children[0].test()});
}
template <> bool LogicalActivation<2>::test() {
  return operation({children[0].test(), children[1].test()});
}

template <>
std::size_t Hashable::multiVarHash<std::string, std::array<EventActivation, 2>>(
    std::string classId, std::array<EventActivation, 2> children) {

  // Compute individual hash values for first, second and third
  // http://stackoverflow.com/a/1646913/126995
  size_t res = 17;
  res = res * 31 + std::hash<std::string>()(classId);
  res = res * 31 + std::hash<Hashable>()(children[0]);
  res = res * 31 + std::hash<Hashable>()(children[1]);
  return res;
};

template <>
std::size_t Hashable::multiVarHash<std::string, std::array<EventActivation, 1>>(
    std::string classId, std::array<EventActivation, 1> children) {

  // Compute individual hash values for first, second and third
  // http://stackoverflow.com/a/1646913/126995
  size_t res = 17;
  res = res * 31 + std::hash<std::string>()(classId);
  res = res * 31 + std::hash<Hashable>()(children[0]);
  return res;
};

template <>
Hashable::Hashable(std::string classId, std::array<EventActivation, 2> children)
    : hasher(
          std::bind(multiVarHash<std::string, std::array<EventActivation, 2>>,
                    classId, children)) {}

template <>
Hashable::Hashable(std::string classId, std::array<EventActivation, 1> children)
    : hasher(
          std::bind(multiVarHash<std::string, std::array<EventActivation, 1>>,
                    classId, children)) {}