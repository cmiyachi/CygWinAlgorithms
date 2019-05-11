#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string str) {
    int count=0;
    char ch=str[0];
    for(int i=1;i<str.length();i++)
    {
        if(ch==str[i])
            count++;
        else
            ch=str[i];
    }
    return count;


}
int main()
{
	string s;
	cin>>s;
	cout<<alternatingCharacters(s);
}