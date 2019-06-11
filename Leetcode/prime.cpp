#include <iostream>
using namespace std;
#include <vector> 

bool isPrimeNaive(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i ++) {
     if (n % i == 0) return false;
  }
  return true;
}
int countPrimesNaive(int n) {
	int c = 0;
  for (int i = 2; i < n; i ++) {
    if (isPrimeNaive(i)) c ++;
  }
  
  return c; 
}

/*However, the above O(n) isPrime check is not efficient. With counting O(n) that makes the overall 
complexity O(n^2) which is bad when n gets large. We know that the number must not be divisible by any number > n / 2, 
and we can replace i < n with i < n/2.

Further, we know that we only need to consider factors up to √n because, if n is divisible by number p, 
then n = p × q and since p ≤ q, we know p ≤ √n.
*/ 
bool isPrime(int num) {
   if (num <= 1) return false;
   // Loop's ending condition is i * i <= num instead of i <= sqrt(num)
   // to avoid repeatedly calling an expensive function sqrt().
   for (int i = 2; i * i <= num; i++) {
      if (num % i == 0) return false;
   }
   return true;
}

// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Algorithm_complexity.  https://helloacm.com/c-coding-exercise-count-primes/

int countPrimes(int n) {
   int count = 0;
   for (int i = 1; i < n; i++) {
      if (isPrime(i)) count++;
   }
   return count;
}
 


int main() {
	//code
	cout << countPrimes(10); 
	return 0;
}