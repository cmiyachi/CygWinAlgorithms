#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
		int count = 0;
		for (int i = 0; i < J.size(); i++)
		{
			// for each jewel - look for it in stones 
			size_t found = S.find(J[i]); 
			// count++;
			while(found != string::npos)
			{
				count++;
				found = S.find(J[i],found+1);
			}
		}
		return count;
    }
};

int main(void)
{
	Solution sol;
	string J = "aA", S = "aAAbbbb"; 
	cout << sol.numJewelsInStones(J,S);
	
	return 0;
}