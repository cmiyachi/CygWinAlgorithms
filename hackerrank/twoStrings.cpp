/*
Given two strings, determine if they share a common substring. A substring may be as small as one character.
For example, the words "a", "and", "art" share the common substring . The words "be" and "cat" do not share a substring.
Function Description
Complete the function twoStrings in the editor below. It should return a string, either YES or NO based on whether the strings share a common substring.
twoStrings has the following parameter(s):
s1, s2: two strings to analyze .
Sample Input
2
hello
world
hi
world
Sample Output
YES
NO
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    
	if(s1.length()<=s2.length())
	{
		for(int i=0;i<s1.length();i++)
		{
			if(s2.find(s1[i]) != string::npos)
				return "YES";
		}
		return "NO";
	}
    else
    {
            for(int i=0;i<s2.length();i++)
            {
                if(s1.find(s2[i]) != string::npos)
                    return "YES";
            }
            return "NO";
        
        
    }

}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<twoStrings(s1,s2)<<endl;
}