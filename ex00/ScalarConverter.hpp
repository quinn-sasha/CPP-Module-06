#ifndef EX00_SCALARCONVERTER_HPP_
#define EX00_SCALARCONVERTER_HPP_

#include <string>

class ScalarConverter {
  ScalarConverter();
  ScalarConverter(const ScalarConverter&);
  ScalarConverter& operator=(const ScalarConverter&);
  ~ScalarConverter();

 public:
  static void convert(const std::string& str);
};

#endif  // EX00_SCALARCONVERTER_HPP_
