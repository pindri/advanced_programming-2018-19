#ifndef _FUNC_H_
#define _FUNC_H_

#include <iostream>

void dummy() {  // if I static or inline this then it works
  std::cout << "dummy\n";
}

#endif /* _FUNC_H_ */
