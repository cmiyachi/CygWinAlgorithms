#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int num_of_tests = 0;
    vector<string> input; 
	
	
    cin >>  num_of_tests;
	//cout << num_of_tests << endl;
    for (int i = 0; i < num_of_tests; i++)
    {
        string s;
        vector<char> even, odd; 
        cin >> s;
		//cout << s << endl;
        for (int j = 0; j < s.length(); j++) 
        {
			// cout << "j " << j << " char " << s[j] << endl;
            if ((j%2 ==0) ||  (j == 0))
                even.push_back(s[j]);
            else  odd.push_back(s[j]);
        }
		for (int k = 0; k < even.size(); k++)
		cout << even[k];
		cout << " "; 
		for (int k = 0; k < odd.size(); k++)
			cout << odd[k]; 
        cout << endl;
    }

	

    return 0;
}
