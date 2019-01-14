#include <iostream>
#include <cmath>

/**
 * @file prime.cc
 * @brief Computes and prints all the prime numbers smaller or equal than a
 * given int n
 *
 * @author Patrick Indri
 * @date 13/01/19
 *
 * The first approach counts the number of prime numbers
 * and allocates an array of that dimension.
 * It then computes the prime numbers again and fills the array.
 *
 * The second approach uses the properties of the prime-counting function.
 * In particular pi(n) <= 1.25506n/log(n), where pi(n) is the number
 * of prime numbers less or equal than n.
 * For n>=60184 a more restrictive upper bound can be used.
 */



/*!
 * @brief Determines wether a number is prime or not.
 *
 * @param n number to be tested
 * @return 0 if not prime, 1 if prime
 */

int is_prime(const int n){
  for (int i = 2; i <= std::sqrt(n); i++){
    if ( n%i == 0 ) return 0;
  }
  
  return 1;
}

/*!
 * @brif naive implementation, counts the number of primes and allocates
 * proper array. It then fills the array and prints it.
 *
 * @param n upper limit for the prime-number search
 * @return pointer to the array of primes
 */


int* naive_primes(const int n) {

  int array_dim = 0;

  for (int i = 2; i <=n; i++){
    array_dim += is_prime(i);  
  }

  std::cout << "there are " << array_dim << " prime numbers less or equal than "<< n << std::endl;

  int* result{new int[array_dim]};

  int j = 0;
  for (int i = 2; i <= n; i++){
    if (is_prime(i) == 1) {
      result[j] = i;
      std::cout << j+1 << ":\t"<< i << std::endl;
      j += 1;
      }
  }

  return &result[0];

}


/*!
 * @brief smarter implementation. Allocates an array large enough to
 * contain the first prime numbers up to n. It then fills the array and prints it.
 *
 * @param n upper limit for the prime-number search
 * @return pointer to the array of primes
 */

int* smarter_prime(const int n) {

  int array_dim = 1.25506*((n*1.0)/(log(n))); //properties of the prime-counting funcion
  if (n>=60184) array_dim = (n*1.0)/(log(n)-1.1);

  int* result{new int[array_dim]};

  int count = 0;
  for (int i = 2; i <= n; i++){
    if (is_prime(i) == 1) {
      result[count] = i;
      std::cout << count+1 << ":\t"<< i << std::endl;
      count += 1;
      }
  }
  
  std::cout << "percentage of wasted memory: " << ((array_dim-count)*1.0)/(array_dim*1.0)*100 << "%" << std::endl;

  return &result[0];
}





int main() {


  int n;
  std::cout<<"insert number n: "<<std::endl;
  std::cin >> n;


  auto n_primes = naive_primes(n);
  std::cout<<"primes[1] = "<<n_primes[1]<<std::endl; 

  auto s_primes = smarter_prime(n);
  std::cout<<"primes[1] = "<<s_primes[1]<<std::endl;


}



