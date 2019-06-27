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
	string J = "aA"; 
	string S = "aAAbbbb"; 
	
	Solution s; 
	
	cout << s.numJewelsInStones(J,S) << endl;;
	
	J = "z"; S = "ZZ"; 
	
	cout << s.numJewelsInStones(J,S) << endl;;
	
	return 0;
}