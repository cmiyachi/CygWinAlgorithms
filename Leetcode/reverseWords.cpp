/// https://leetcode.com/problems/reverse-words-in-a-string/

#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    
    void reverse(string &s,int begin,int end){
        while(begin<=end){
            swap(s[begin],s[end]);
            begin++;
            end--;
        }
    }
    
    string reverseWords(string A) {
        /// step 1
        int begin = 0;
        int end = 0;
        while(end<A.size()){
            if(A[end]==' '){
                reverse(A,begin,end-1);
                end++;
                begin = end;
            }else{
                end++;
            }
        }
        reverse(A,begin,end-1);   /// last word
        
        reverse(A,0,A.size()-1); /// reversing complete string
        
        string help;
        
        int i=0;
        while(A[i]==' ') i++;   /// leading spaces
        while(i<A.size()){
            if(A[i]==' '){
                help.push_back(' ');
                i++;                        //// multiplce space into single space
                while(A[i]==' ') i++;
            }else{
                help.push_back(A[i]);
                i++;
            }
        }
        
        /// trailing space
        if(help.back()==' ') help.pop_back();
        
        
        return help;
    }
};

class Solution4 {
public:
    
	// O(N)
    string curateString(string s) {
        int startInd = 0;
        int endInd = s.length()-1;
        
        // O(N) for this while loop and the substring method (on the return line).
		// The while loop goes through the leading and trailing whitespace,
		// and the substring method is O(N) with respect to the length of the 
		// new string. So in total, this function is O(N).
        while(s[startInd] == ' ' || s[endInd] == ' ') {
            if(s[startInd] == ' ') {
                startInd++;
            }
            if(s[endInd] == ' ') {
                endInd--;
            }
        }
        
        return s.substr(startInd, endInd-startInd+1);
    }
    string reverseWords(string s) {
        string ret = "";
        stack<string> stk;
        
        string curatedStr = curateString(s);
        
        string word = "";
        bool inWhiteSpace = false;
        
        // O(N)
        for(int i = 0; i < curatedStr.length(); i++) {
            if(curatedStr[i] != ' ') {
                inWhiteSpace = false;
                word += curatedStr[i];
            } else if (curatedStr[i] == ' ' && !inWhiteSpace) {
                inWhiteSpace = true;
                stk.push(word);
                word = "";
            }
        }
        stk.push(word);
        
		// O(N) time
        while(!stk.empty()) {
            ret += stk.top();
            ret += " ";
            stk.pop();
        }
        // Pop off the excess whitespace
        ret.pop_back();
        
        return ret;
    }
};
class Solution2 {
public:
    string reverseWords(string s) {
        if (s.empty()) return "";
        int l = 0, r = 0;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                s[r++] = s[i];
            }
            else if (i > 0 and s[i-1] != ' ') {
                reverse(s.begin() + l, s.begin() + r);
                s[r++] = ' ';
                l = r;
            }
        }
        reverse(s.begin() + l, s.begin() + r);
        r = r > 0 and s[r - 1] == ' ' ? r - 1 : r;
        return s.substr(0, r);
    }
};


class Solution3 {
public:
    
    vector<string> getWords(string str)
    {
        // Used to split string around spaces.
        istringstream ss(str);
        vector<string> result; 

        string word; // for storing each word

        // Traverse through all words
        // while loop till we get 
        // strings to store in string word
        while (ss >> word) 
        {
            // print the read word
           // cout << word << "\n";
            result.push_back(word);
        }
        return result; 
    }
    string reverseWords(string s) {
        vector<string> result = getWords(s);
        reverse(result.begin(), result.end());
        string final_string = "";
        
        for (int i = 0; i < result.size()-1; i++)
            final_string = final_string+result[i]+" "; 
        final_string = final_string+ result[result.size()-1];
        
        return final_string; 

    }
};

int main(void)
{
	
	string s = "  Bob    Loves  Alice   "; 
	Solution sol;
	
	cout << sol.reverseWords(s);
	
	return 0;
}
