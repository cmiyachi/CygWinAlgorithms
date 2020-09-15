#include <bits/stdc++.h> 
using namespace std; 

class Solution2 {
public:
    string licenseKeyFormatting(string S, int K) {
        string str ="";
        int c=0;
        for(int i=S.size()-1; i >= 0; --i){
            if(c == K && S[i] != '-'){
                str = ((char)toupper(S[i])) + ('-' + str);
                c = 1;
            } else if(S[i] != '-'){
                ++c;
                str = ((char)toupper(S[i])) + str;
            } 
        }
        
        return str;
    }
};

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result;
		transform(S.begin(), S.end(), S.begin(), ::toupper);
        int index = S.size();
        int tempK = 0;
        while(--index >= 0){
            if(S[index] != '-'){
                if(tempK == K){
                    result += '-';
                    tempK = 0;
                }
                result += S[index]; //(isalpha(S[index]) ? char(toupper(S[index])) : S[index]);
                tempK++;
            }
        }
        return string(result.rbegin(), result.rend());
    }
};

int main(void)
{
	Solution sol;
	
	string S = "5F3Z-2e-9-w";
	int K = 4;
	
	cout << sol.licenseKeyFormatting(S, K)<< endl;
	return 0;
}