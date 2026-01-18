#include <cassert>
#include <cstdint>

#include "Data.hpp"
#include "Serializer.hpp"

int main() {
  Data* original_ptr = new Data(42);
  std::uintptr_t ptr_value = Serializer::serialize(original_ptr);
  Data* copied_ptr = Serializer::deserialize(ptr_value);
  assert(original_ptr == copied_ptr);

  delete original_ptr;
}
