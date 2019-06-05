#include <bits/stdc++.h>

using namespace std;

bool regexMatching(std::string pattern, std::string test) {
    //cout  << pattern.substr(0,pattern.length()-1) << " " << test.substr((test.length())-(pattern.length()-1),pattern.length()-1) << endl;
    
    // Pattern checking
    if (pattern[0] == '^')
        return pattern.substr(1,pattern.length()-1) == test.substr(0,pattern.length()-1);
    else if (pattern.back() == '$')
        return pattern.substr(0,pattern.length()-1) == test.substr(test.length()-(pattern.length()-1),pattern.length()-1);
    
    int i = 0;
    while (i < test.length() ){
        
        while (i < test.length() && pattern[0] != test[i] ) i++;
        
        if (i < test.length() && pattern[0] == test[i]) {
            int j = 0;
            while (j< pattern.length() && test[i++] == pattern[j++]) {}
            
            if (j == pattern.length() && test[i-1] == pattern[j-1]) return true;
            
            //i++;
            
        }
    }
    
    
    return false;
}

int main(void)
{
	string pattern = "^code"; 
	string test = "codesignal"; 
	cout << regexMatching(pattern, test) << endl;; 
	
	pattern = "nal$";
	
	cout << regexMatching(pattern, test) << endl;; 
	
	pattern = "hello";
	test = "world";
	cout << regexMatching(pattern, test) << endl;; 
	
	return 0;
}