#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate() {
  int random_index = rand() % 3;
  if (random_index == 0) {
    return new A;
  }
  if (random_index == 1) {
    return new B;
  }
  return new C;
}

void identify(Base* ptr) {
  if (dynamic_cast<A*>(ptr)) {
    std::cout << "A\n";
    return;
  }
  if (dynamic_cast<B*>(ptr)) {
    std::cout << "B\n";
    return;
  }
  if (dynamic_cast<C*>(ptr)) {
    std::cout << "C\n";
    return;
  }
  std::cout << "Base\n";
  return;
}

void identify(Base& ref_base) {
  try {
    (void)dynamic_cast<A&>(ref_base);
    std::cout << "A\n";
    return;
  } catch (const std::bad_cast&) {
    // Do nothing
  }
  try {
    (void)dynamic_cast<B&>(ref_base);
    std::cout << "B\n";
    return;
  } catch (const std::bad_cast&) {
  }
  try {
    (void)dynamic_cast<C&>(ref_base);
    std::cout << "C\n";
    return;
  } catch (const std::bad_cast&) {
  }
  std::cout << "Base\n";
}

int main() {
  std::srand((unsigned int)std::time(NULL));

  for (int i = 0; i < 3; i++) {
    Base* base_ptr = generate();
    identify(base_ptr);
    identify(*base_ptr);
    delete base_ptr;
  }
}
