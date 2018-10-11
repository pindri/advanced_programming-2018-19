#include <iostream>
#include <array>


int main()
{
  std::array<int,4> a{1,2,3,4}; 
  std::array<int,4> b{a};

  for (auto x : a)
    std::cout << x << " ";
  std::cout << std::endl;

  for (auto x : b)
    std::cout << x << " ";
  std::cout << std::endl;

  a[0] = 0;

  for (const auto x : a)
    std::cout << x << " ";
  std::cout << std::endl;

  for (const auto x : b)
    std::cout << x << " ";
  std::cout << std::endl;

  for (auto& x : a)
    x*=10;
  
  for (const auto x : a)
    std::cout << x << " ";
  std::cout << std::endl;

  b.at(90);
  
  return 0;
}
