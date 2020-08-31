#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string r = "";
        int sz1 = num1.size();
        int sz2 = num2.size();
        int i = 0, j = 0, c = 0;
        while (i < sz1 || j < sz2 || c > 0) {
            int t = c;
            t += i < sz1 ? num1[sz1 - i - 1] - 48 : 0;
            t += j < sz2 ? num2[sz2 - j - 1] - 48 : 0;
            r = string(1, t % 10 + 48) + r;
            c = t / 10; // carry over next digit
            i ++;
            j ++;
        }
        return r;
    }
};
class Solution2 {
public:
string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');
    
		for (int i = num1.size() - 1; 0 <= i; --i) {
			int carry = 0;
			for (int j = num2.size() - 1; 0 <= j; --j) {
				int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
				sum[i + j + 1] = tmp % 10 + '0';
				carry = tmp / 10;
			}
			sum[i] += carry;
		}
		
		size_t startpos = sum.find_first_not_of("0");
		if (string::npos != startpos) {
			return sum.substr(startpos);
		}
		return "0";
	}
    
};

class Solution3 {
public:
	string multiply(string num1, string num2) {
		
		// convert num1 and num2 into numbers
		// object from the class stringstream 
		stringstream numstring1(num1); 
		stringstream numstring2(num2); 
		long long n1 = 0, n2 = 0; 
		
		numstring1 >> n1; 
		numstring2 >> n2; 
		
		long long output = n1*n2; 
		
		// convert output to string
		return(to_string(output));
	}
    
};

int main(void)
{
	string num1 = "123", num2 = "456";
	Solution sol;
	
	cout << sol.multiply(num1, num2) << endl; 
	
	Solution2 sol2;
	
	cout << sol2.multiply(num1, num2) << endl; 
	
	Solution3 sol3;
	
	cout << sol3.multiply(num1, num2) << endl; 
	
	return 0;
}

