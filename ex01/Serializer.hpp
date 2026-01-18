#ifndef EX01_SERIALIZER_HPP_
#define EX01_SERIALIZER_HPP_

#include <stdint.h>

#include "Data.hpp"

class Serializer {
  Serializer();
  Serializer(const Serializer& other);
  Serializer& operator=(const Serializer& other);
  ~Serializer();

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

#endif  // EX01_SERIALIZER_HPP_
