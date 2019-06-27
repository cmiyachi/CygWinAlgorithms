#include <bits/stdc++.h>

using namespace std;

bool isSentenceCorrect(std::string sentence) {
  std::regex regex("[A-Z][^.?!]*[.?!]$");
  return std::regex_match(sentence, regex);
}

int main(void)
{
	string s1 ="!this sentence is TOTALLY incorrecT"; 
	
	string s2 = "This is an example of *correct* sentence."; 
	
	cout << isSentenceCorrect(s1) << endl;
	cout << isSentenceCorrect(s2) << endl;
	
	return 0;
}