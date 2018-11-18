#include<iostream>
#include<string>

/*
 * This program reads from stdin an array of given size and type and then prints it in reverse.
 */

template <typename T>
T* write(const size_t n);

template <typename T>
void print(T* array, const size_t n);


int main() {

  std::size_t n;
  std::cout << "insert array size: n = ";
  std::cin >> n;

  float* a{write<float>(n)};
  //std::cout << a << std::endl;
  print(a,n);

  delete[] a;

  }

template <typename T>
T* write(const size_t n) {

  T* ar{new T[n]};
  std::cout << "insert " << n << " " << typeid(ar[0]).name() << " elements" << std::endl;
  
  for (std::size_t i{0}; i < n; ++i){
    std::cout << i+1 << ": ";
    std::cin >> ar[i];
  }
  
  return &ar[0];
}


template <typename T>
void print(T* array, const size_t n) {
  std::cout << "printing reversed array" << std::endl;
  for (std::size_t i{0}; i < n; ++ i) {
    std::cout << n-i << ": " << array[n-i-1] << std::endl;
  }
}


