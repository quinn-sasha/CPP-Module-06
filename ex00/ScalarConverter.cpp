#include "ScalarConverter.hpp"

#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

namespace {
void print_one_character(const std::string& str) {
  int int_converted = static_cast<int>(str[0]);
  if (int_converted < 0 || int_converted > 127) {
    std::cout << "char: impossible\n";
    return;
  }
  char converted = static_cast<char>(int_converted);
  if (!std::isprint(converted)) {
    std::cout << "char: Non displayable\n";
    return;
  }
  std::cout << "char: " << converted << "\n";
}

void print_converted_char(const std::string& str, double d_converted) {
  if (str.size() == 1) {
    print_one_character(str);
    return;
  }
  // Convert numerical lieterals like 100 from here
  if (d_converted < 0 || d_converted > 127) {  // implicit conversion!
    std::cout << "char: impossible\n";
    return;
  }
  char converted = static_cast<char>(d_converted);
  if (!std::isprint(converted)) {
    std::cout << "char: Non displayable\n";
    return;
  }
  std::cout << "char: " << converted << "\n";
}

void print_converted_int(double from) {
  if (from < std::numeric_limits<int>::min() ||  // implicit conversion
      from > std::numeric_limits<int>::max()) {
    std::cout << "int: impossible\n";
    return;
  }
  int converted = static_cast<int>(from);
  std::cout << "int: " << converted << "\n";
}

void print_converted_float(double from) {
  if (std::isnan(from)) {
    std::cout << "float: nanf\n";
    return;
  }
  if (from < std::numeric_limits<float>::lowest()) {
    std::cout << "float: -inff\n";
    return;
  }
  if (from > std::numeric_limits<float>::max()) {
    std::cout << "float: +inff\n";
    return;
  }
  float converted = static_cast<float>(from);
  std::cout << std::fixed << std::setprecision(1) << "float: " << converted
            << "f\n";
}

void print_double(double converted) {
  if (std::isnan(converted)) {
    std::cout << "double: nan\n";
    return;
  }
  if (std::isinf(converted)) {
    std::cout << "double: " << converted << "\n";
    return;
  }
  std::cout << std::fixed << std::setprecision(1) << "double: " << converted
            << "\n";
}
}  // namespace

// No need to implement --------------------
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
  return *this;
}

ScalarConverter::~ScalarConverter() {}
// -----------------------------------------

void ScalarConverter::convert(const std::string& str) {
  char* endptr;
  double d_converted = strtod(str.c_str(), &endptr);
  if (*endptr != '\0' && std::string(endptr) != "f" && str.size() != 1) {
    std::cout << "Every conversion is impossible\n";
    return;
  }
  if (errno == ERANGE) {
    std::cout << "Every conversion is impossible\n";
    return;
  }

  bool prints_only_floating_point =
      std::isnan(d_converted) || std::isinf(d_converted);
  if (prints_only_floating_point) {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
  } else {
    print_converted_char(str, d_converted);
    print_converted_int(d_converted);
  }
  print_converted_float(d_converted);
  print_double(d_converted);
}
