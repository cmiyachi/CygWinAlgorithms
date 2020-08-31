#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
			}
			else
			{
				digits[i]++;
				return digits;
			}
		}
		digits[0] =1;
		digits.push_back(0);
		return digits;
        
    }
};

int main(void)
{
	
	vector<int> digits{1,2,3};
	vector<int> digits2{4,3,2,1};
	vector<int> digits3{9,9,9,9};
	Solution sol;
	
	vector<int> results = sol.plusOne(digits);
	for (auto x: results)
		cout << x << " "; 
	cout << endl;
	
	vector<int> results2 = sol.plusOne(digits2);
	for (auto x: results2)
		cout << x << " ";
	cout << endl;
	vector<int> results3 = sol.plusOne(digits3);
	for (auto x: results3)
		cout << x << " ";
	cout << endl;
	return 0;
}