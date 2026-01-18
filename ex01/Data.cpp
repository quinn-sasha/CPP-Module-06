#include "Data.hpp"

Data::Data() : value_(0) {}

Data::Data(int value) : value_(value) {}

Data::Data(const Data& other) : value_(other.value_) {}

Data& Data::operator=(const Data& other) {
  if (this == &other) {
    return *this;
  }
  value_ = other.value_;
  return *this;
}

Data::~Data() {}
