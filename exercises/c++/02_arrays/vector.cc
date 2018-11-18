





#include<iostream>
#include<cmath>
#include<vector>


int is_prime (const unsigned int);



int main() {

	int n;

	std::cout << "insert number n: ";
	std::cin >> n;

	std::vector<int> vect, sieve(n, 1);

	int j = 0;

	for (int i{2}; i<=n; i++){
		if (is_prime(i) == 1){
		      	vect.push_back(i);
			std::cout << j+1 << ":\t" << i << std::endl;
			j += 1;
		}
	}

	j = 0;

	for (int i{2}; i<std::sqrt(n); i++){
		if (sieve[i] == 1) {
			j = i * i;
			while (j<=n){
				sieve[j] = 0;
				j += i;
			}
		}
	}


	std::cout << "Sieve of E.: " << std::endl;

	int count = 1;
 	for (int i = 2; i <= n; i++){
		if (sieve[i] == 1){
			std::cout << count << ":\t"<< i << std::endl;
			count += 1;
    		}
  	}


}



int is_prime(const unsigned int n){
	for (int i{2}; i <= std::sqrt(n); i++){
		if (n%i == 0) return 0;
	}
	return 1;

}
