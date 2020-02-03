#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans; 
        
        for (int num = 1; num <= n; num++)
        {
            bool divBy3 = (num % 3 == 0);
            bool divBy5 = (num % 5 == 0);
            
            string numAns = ""; 
            
            if (divBy3) numAns += "Fizz";
            if (divBy5) numAns += "Buzz"; 
            
            if (numAns == "")
            {
                numAns += to_string(num);
            }
     
            ans.push_back(numAns); 
            
        }
        
        return(ans);
    }
};


int main(void)
{
	Solution sol;
	
	vector<string> result = sol.fizzBuzz(15);
	
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}