#include "Serializer.hpp"

#include <cstdint>

#include "Data.hpp"

// No need to implement --------------
Serializer::Serializer() {}

Serializer::Serializer(const Serializer&) {}

Serializer& Serializer::operator=(const Serializer&) { return *this; }

Serializer::~Serializer() {}
// -----------------------------------

std::uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<std::uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}
