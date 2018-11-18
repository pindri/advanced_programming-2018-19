#include <iostream>
#include <cmath>

/* 
 * The code computes and prints all the prime numbers smaller or equal than a given int n.
 *
 * The first approach counts the number of prime numbers and allocates an array of that dimension. It then computes the prime numbers again and fills the array.
 *
 * The second approach uses the properties of the prime-counting function. In particular pi(n) <= 1.25506n/log(n), where pi(n) is the number of prime numbers less or equal than n. For n>=60184 a more restrictive upper bound can be used.
 */



int is_prime(const unsigned int n);



int main() {

//------------FIRST METHOD------------

  int count = 0;
  int n;

  std::cout << "insert number n: ";
  std::cin >> n;

  for (int i = 2; i <=n; i++){
    count += is_prime(i);  
    //std::cout << count << std::endl;	
  }

  std::cout << "there are " << count << " prime numbers less or equal than "<< n << std::endl;

  int* result{new int[count]};
  int j = 0;

  for (int i = 2; i <= n; i++){
    if (is_prime(i) == 1) {
      result[j] = i;
      std::cout << j+1 << ":\t"<< i << std::endl;
      j += 1;
      }
  }

  delete[] result;

  std::cout << " " << std::endl;
  
//----------SECOND METHOD-------------

  int count2 = 1.25506*((n*1.0)/(log(n)));

  if (n>=60184) count2 = (n*1.0)/(log(n)-1.1);

  //std::cout << "count2 = " << count2 << std::endl;
 
  int* result2{new int[count2]};

  j = 0;
  for (int i = 2; i <= n; i++){
    if (is_prime(i) == 1) {
      result2[j] = i;
      std::cout << j+1 << ":\t"<< i << std::endl;
      j += 1;
      }
  }



  //std::cout << "count2 - count = " << count2-count << std::endl;

  std::cout << "percentage of wasted memory: " << ((count2-count)*1.0)/(count*1.0)*100 << "%" << std::endl;

  delete[] result2;


}



int is_prime(const unsigned int n){
  for (int i = 2; i <= std::sqrt(n); i++){
    if ( n%i == 0 ) return 0;
  }
  
  return 1;
}


