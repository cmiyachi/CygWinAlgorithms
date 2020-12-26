#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
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
 
};

class Solution {
public:
    
    vector<int> prime;
    
    bool check_prime(int num){
        for(auto it : prime){
            if(num%it==0)
                return false;
            if(it > sqrt(num))
                break;
        }
        return true;
    }
    
    
    int countPrimes(int n) {
        if(n<=2)
            return 0;
        int result =0;
        prime.push_back(2);
        for(int i=3;i<n ;i+=2){
            if(check_prime(i))
                prime.push_back(i);
        }
        return prime.size();
    }
};

class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime = primelist(n);   // get a list of primes

        int total = 0;
        for(int i = 0; i < prime.size(); i++)   // count the primes
            if(prime[i] < n)
                total++;
            else
                break;

        return total;
    }

    vector<int> primelist(int n) {
        vector<int> vis(n + 1, false);
        vector<int> prime;

        // producing prime number list
        for(long long i = 2; i <= n; i++) {
            if(vis[i])
                continue;
            else {
                prime.push_back(i);
                for(long long j = i * i; j <= n; j += i)
                    vis[j] = true;
            }
        }
        return prime;
    }
};