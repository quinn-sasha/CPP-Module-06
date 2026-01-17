#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Usage: ./convert <number>\n";
    return 1;
  }
  ScalarConverter::convert(argv[1]);
}
