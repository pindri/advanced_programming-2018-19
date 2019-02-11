#ifndef __class__
#define __class__

#include <iostream>

struct A {
  int a;
  A(); // if I inline this it works
};

A::A() {
  std::cout << "A ctor\n";
}

#endif
