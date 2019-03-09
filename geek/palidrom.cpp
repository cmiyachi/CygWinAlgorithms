#include <iostream>
#include <string> 
#include <vector>
using namespace std;

int main() {
	int n, num, digit, rev = 0, testcases;
	vector<string> results; 

     //cout << "Enter a positive number: ";
     cin >> testcases;
	 for (int i = 0; i < testcases;i++)
	 {
		cin >> num; 
		rev = 0; 
		
		int numtemp, sum = 0;
		
		numtemp = num; 
		while (numtemp != 0)
		{
			sum = sum + numtemp % 10;
			numtemp = numtemp / 10;
		}

		 n = sum;
		// cout << "sum " << sum << endl;

		 do
		 {
			 digit = sum % 10;
			 rev = (rev * 10) + digit;
			 sum = sum / 10;
		 } while (sum != 0);
		 
		if (n == rev)
			results.push_back("YES");
			//cout << "YES" << endl;
		else
			// cout << "NO" << endl; 
			results.push_back("NO");
	 } // for 
	 
	 for (auto& it : results) {
		cout << it << endl;
	}
		//  cout << results[j] << endl; 
	
	return 0;
}