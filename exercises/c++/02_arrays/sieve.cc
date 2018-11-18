#include <iostream>
#include <cmath>

/*
 * This code computes and prints the prime numbers less or equal than a given integer n though an implementation of the Sieve of Eratosthenes.
 * The algorithm is optimized by enumerating the multiples of each prime i starting from i*i.
 * */


int main() {

  int n;

  std::cout << "insert an integer: n = ";
  std::cin >> n;

  // an array of dimension n is allocated and initialized to TRUE

  int* ar{new int[n]};
  for (int i = 0; i <= n; i++) {
    ar[i] = 1;
  }

  // the sieve of Eratosthenes is implemented in the following loop

  int j = 0;
  for (int i = 2; i<std::sqrt(n); i++){
    if (ar[i] == 1) {
      j = i*i;
      while (j<=n){
        ar[j] = 0; // all multiples of i are set to FALSE
        j = j + i;
      }
    }
  }

  // all the index of all the TRUE elements are printed

  int count = 1;
  for (int i = 2; i <= n; i++){
    if (ar[i] == 1){
      std::cout << count << ": "<< i << std::endl;
      count += 1;
    }
  }

}
