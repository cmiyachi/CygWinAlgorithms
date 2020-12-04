/*
Overview
The problem could be solved in many ways. Easy approaches have \mathcal{O}(N^2)O(N 
2
 ) time complexity, though one could improve it by using one of string searching algorithms.

overview



Approach 1: Regex
To use regex during the interviews is like to use built-in functions, the community has no single opinion about it yet, and it's a sort of risk.
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        regex pat("^(.+)\\1+$");
        return regex_match(s, pat);
    }
};

/*
Complexity Analysis

Time complexity: \mathcal{O}(N^2)O(N 
2
 ) because we use greedy regex pattern. Once we have a +, the pattern is greedy.

The difference between the greedy and the non-greedy match is the following:

the non-greedy match will try to match as few repetitions of the quantified pattern as possible.

the greedy match will try to match as many repetitions as possible.

The worst-case situation here is to check all possible pattern lengths from N to 1 that would result in \mathcal{O}(N^2)O(N 
2
 ) time complexity.

Space complexity: \mathcal{O}(1)O(1). We don't use any additional data structures, and everything depends on internal regex implementation, which is evolving quite fast nowadays. If you're interested to dig depeer, here is a famous article by Russ Cox which inspired a lot of discussions and code changes in Python community.



Approach 2: Concatenation
Repeated pattern string looks like PatternPattern, and the others like Pattern1Pattern2.

Let's double the input string:

PatternPattern --> PatternPatternPatternPattern

Pattern1Pattern2 --> Pattern1Pattern2Pattern1Pattern2

Now let's cut the first and the last characters in the doubled string:

PatternPattern --> *atternPatternPatternPatter*

Pattern1Pattern2 --> *attern1Pattern2Pattern1Pattern*

It's quite evident that if the new string contains the input string, the input string is a repeated pattern string.

Implementation

Complexity Analysis

Time complexity: \mathcal{O}(N^2)O(N 
2
 ) because of the way in and contains are implemented.

Space complexity: \mathcal{O}(N)O(N), the space is implicitly used to keep s + s string.

*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2 * s.size() - 2).find(s) != string::npos;
    }
};

/*
pproach 3: Find Divisors + Rabin-Karp
Rabin-Karp

Rabin-Karp is a linear-time \mathcal{O}(N)O(N) string searching algorithm:

Move a sliding window of length LL along the string of length NN.

Check hash of the string in the sliding window.

rabin_karp

In some situations, one has to implement a particular hash algorithm to fit in a linear time, for example, we used rolling hash algorithm for the problem Longest Duplicate Substring.

For the current problem the standard hash / hashCode is enough because the idea is to check only lengths L, which are divisors of N. This way we're not sliding, we're jumping:

the first string is 0..L

the second string is L..2L

...

the last string is N - L..N

To copy characters in sliding window takes time L, to compute hash - time L as well. In total, there are N / L substrings, that makes it all work in a linear time \mathcal{O}(N)O(N).

Find divisors

Now the only problem is to find divisors of N. Let's iterate to the square root of N, and for each identified divisor i calculate the paired divisor N / i.

Algorithm

Deal with base cases: n <= 2.

Iterate from \sqrt{n} 
n
​	
  to 1.

For each divisor n % i == 0:

Compute paired divisor n / i.

Use Rabin-Karp to check substrings of the lengths l = i and l = n / i:

Take as a reference hash first_hash the hash of the first substring of length l.

Jump along the string with a step of length l while the hash of the current substring is equal to first_hash.

If the hashes of all substrings along the way are equal, the input string consists of repeated patterns of length l. Return True.

Side note. The good practice is to verify the equality of two substrings after the hash match. This logic is not hard to add, and it could bring you kudos during the interview.*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if (n < 2) return false;
        if (n == 2) return s[0] == s[1];    
            
        for (int i = sqrt(n); i > 0; i--) {
            if (n % i == 0) {
                vector<int> divisors;
                divisors.push_back(i);
                if (i != 1) {
                    divisors.push_back(n / i);    
                }
                for (int l : divisors) {
                    string tmp = s.substr(0, l);
                    int firstHash = hash<string>{}(tmp);
                    int currHash = firstHash;
                    int start = l;
                    while (start != n && currHash == firstHash) {
                        tmp = s.substr(start, l);
                        currHash = hash<string>{}(tmp);
                        start += l;    
                    }
                    if (start == n && currHash == firstHash) {
                        return true;    
                    }    
                }     
            }    
        }     
        return false;
    }
};

/*
Complexity Analysis

Time complexity: up to \mathcal{O}(N \sqrt{N})O(N 
N
​	
 ). \mathcal{O}(\sqrt{N})O( 
N
​	
 ) to compute all divisors and \mathcal{O}(N)O(N) for each divisor "verification". That's an upper-bound estimation because divisor function grows slower than \sqrt{N} 
N
​	
 .

Space complexity: up to \mathcal{O}(\sqrt{N})O( 
N
​	
 ) to keep a copy of each substring during the hash computation.


Approach 4: Knuth-Morris-Pratt Algorithm (KMP)
Lookup Table

Rabin-Karp is the best fit for the multiple pattern search, whereas KMP is typically used for the single pattern search.

The key to KMP is the partial match table, often called lookup table, or failure function table. It stores the length of the longest prefix that is also a suffix.

Here are two examples

kmp_example1

kmp_example2

How to Get an Answer

Once we have a lookup table, we know the length l of common prefix/suffix for the input string: l = dp[n - 1].

That means that n - l should the length of the repeated sequence. To confirm that, one should verify if n - l is a divisor of n.

kmp_solution_example_1

kmp_solution_example_2

Algorithm

Construct lookup table:

dp[0] = 0 since one character is not enough to speak about proper prefix / suffix.

Iterate over i from 1 to n:

Introduce the second pointer j = dp[i - 1].

While j > 0 and there is no match s[i] != s[j], do one step back to consider a shorter prefix: j = dp[j - 1].

If we found a match s[i] == s[j], move forward: j += 1

Write down the length of common prefix / suffix: dp[i] = j.

Now we have a length of common prefix / suffix for the entire string: l = dp[n - 1].

The string is a repeated pattern string if this length is nonzero and n - l is a divisor of n. Return l != 0 and n % (n - l) == 0.

Implementation*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        // Construct partial match table (lookup table).
        // It stores the length of the proper prefix that is also a proper suffix.
        // ex. ababa --> [0, 0, 1, 2, 1]
        // ab --> the length of common prefix / suffix = 0
        // aba --> the length of common prefix / suffix = 1
        // abab --> the length of common prefix / suffix = 2
        // ababa --> the length of common prefix / suffix = 1
        for (int i = 1; i < n; ++i) {
            int j = dp[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = dp[j - 1];    
            }
            if (s[i] == s[j]) {
                ++j;
            }
            dp[i] = j;    
        }

        int l = dp[n - 1];
        // check if it's repeated pattern string
        return l != 0 && l % (n - l) == 0;
    }
};

/*
Time complexity: \mathcal{O}(N)O(N). During the execution, j could be decreased at most NN times and then increased at most NN times, that makes overall execution time to be linear \mathcal{O}(N)O(N).

Space complexity: \mathcal{O}(N)O(N) to keep the lookup table.*/