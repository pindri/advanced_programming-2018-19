/**
 * @file reverse.cc
 * @brief Reads from the stdin an array of given size and type,
 * then prints it in reverse.
 *
 * @author Patrick Indri
 * @date 13/01/19
 *
 */


#include<iostream>
#include<string>


/*!
 * Initializes an array of T-type elements read from stdin
 *
 * @param n number of elements
 * @return pointer to the first element
 */


template <typename T>
T* write_array(const size_t n) {

  T* ar{new T[n]};
  std::cout << "insert " << n << " " << typeid(ar[0]).name() << " elements" << std::endl;
  
  for (std::size_t i{0}; i < n; ++i){
    std::cout << i+1 << ": ";
    std::cin >> ar[i];
  }
  
  return &ar[0];
}

/*!
 * Prints an array of type T elements in reversed order
 *
 * @param array pointer to the first element of the array
 * @param n number of elements of the array
 *
 * @return none
 */

template <typename T>
void print_reverse(T* array, const size_t n) {
  std::cout << "printing reversed array" << std::endl;
  for (std::size_t i{0}; i < n; ++ i) {
    std::cout << n-i << ": " << array[n-i-1] << std::endl;
  }
}

int main() {

  std::size_t n;
  std::cout << "insert array size: n = ";
  std::cin >> n;

  float* a{write_array<float>(n)};
  //std::cout << a << std::endl;
  print_reverse(a,n);

  delete[] a;

  }


