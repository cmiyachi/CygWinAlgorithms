/*
https://leetcode.com/problems/reorder-log-files/
*/
#include <bits/stdc++.h>
	
using namespace std;

class Solution {
public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		if (logs.size() <= 1){
			return logs;
		}
		vector<string>letters;
		vector<string>digits;
		for (int i = 0; i < logs.size(); i++){
			if (isalpha(logs[i][logs[i].find(' ') + 1])){
				letters.push_back(logs[i]);
			}
			else{
				digits.push_back(logs[i]);
			}
		}
		for (int i = letters.size() - 1; i>0; i--){
			for (int j = 0; j < i; j++){
				string str1 = letters[j].substr(letters[j].find(' ') + 1);
				string str2 = letters[j + 1].substr(letters[j + 1].find(' ') + 1);
				cout << "s1" << str1 << str2 << endl; 
				if (str1>str2){
					string temp = letters[j];
					letters[j] = letters[j + 1];
					letters[j + 1] = temp;
				}
				else if (str1 == str2)
				{
					string label1=letters[j].substr(0, letters[j].find(' '));
					string label2=letters[j+1].substr(0, letters[j+1].find(' '));
					cout << "Lable" << label1<< " "<< label2 << endl; 
						if (label1>label2){
						string temp = letters[j];
						letters[j] = letters[j + 1];
						letters[j + 1] = temp;
					}
				}
			}
		}
		letters.insert(letters.end(), digits.begin(), digits.end());
		return letters;
	}
};

int main(){
	/* vector<string>logs = { "a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo" };
	Solution s;
	vector<string>res = s.reorderLogFiles(logs);
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << endl;
	} */
	Solution s; 
	vector<string> logs2= {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo","a2 act car"};
	vector<string>res2 = s.reorderLogFiles(logs2);
	for (int i = 0; i < res2.size(); i++){
		cout << res2[i] << endl;
	}
	return 0;
}