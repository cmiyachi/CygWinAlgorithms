#include <bits/stdc++.h> 
using namespace std;


vector<string> char_map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


void letterCombinations2(string digits, string::size_type n, string &s, vector<string> &v)
	{
		if (n == digits.size()) {
			v.push_back(s);
			return;
		}

		string chars = char_map[digits[n] - '0'];
		for (string::size_type i = 0; i < chars.size(); i++) {
			s += chars[i];
			letterCombinations2(digits, n + 1, s, v);
			s.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> v;
		if (digits == "") return v; 
		string s;
		letterCombinations2(digits, 0, s, v);
		return v;
	}

vector<string> wordsInPhoneNumber(string phoneNumber, vector<string> words) {
  // Write your code here.
	vector<string> result = letterCombinations(phoneNumber);
	vector<string> finalResult;
	
	for (string word : result)
	{
		if (find(words.begin(), words.end(), word) != words.end())
			finalResult.push_back(word); 
	}
  return finalResult;
}
int main(void)
{

	vector<string> result = wordsInPhoneNumber("23", {"ad","ab", "ae","cf"}); 
	
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " , "; 

	cout << endl; 
	
	string phoneNumber = "3662277";
	
	vector<string> words{"foo", "bar", "baz", "foobar", "emo", "cap", "car", "cat"}; 
	result.clear();
	
	result = wordsInPhoneNumber(phoneNumber, words);
		for (int i = 0; i < result.size(); i++)
		cout << result[i] << " , "; 
	return 0;
}