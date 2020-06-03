#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
		// Before proceeding further, make sure length 
		// of num2 is larger. 
		if (num1.length() > num2.length()) 
			swap(num1, num2); 

		// Take an empty string for storing result 
		string str = ""; 

		// Calculate length of both string 
		int n1 = num1.length(), n2 = num2.length(); 

		// Reverse both of strings 
		reverse(num1.begin(), num1.end()); 
		reverse(num2.begin(), num2.end()); 

		int carry = 0; 
		for (int i=0; i<n1; i++) 
		{ 
			// Do school mathematics, compute sum of 
			// current digits and carry 
			int sum = ((num1[i]-'0')+(num2[i]-'0')+carry); 
			str.push_back(sum%10 + '0'); 

			// Calculate carry for next step 
			carry = sum/10; 
		} 

		// Add remaining digits of larger number 
		for (int i=n1; i<n2; i++) 
		{ 
			int sum = ((num2[i]-'0')+carry); 
			str.push_back(sum%10 + '0'); 
			carry = sum/10; 
		} 

		// Add remaining carry 
		if (carry) 
			str.push_back(carry+'0'); 

		// reverse resultant string 
		reverse(str.begin(), str.end()); 

		return str; 
        
    }
};


// Driver code 
int main() 
{ 
	Solution sol; 
	string num1 = "12"; 
	string num2 = "198111"; 
	cout << sol.addStrings(num1, num2); 
	return 0; 
} 
