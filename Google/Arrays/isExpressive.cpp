#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isExpressive(string dst,string src) {
        int i=0,j=0;
        while(i<dst.size() && j<src.size()) {
           if(dst[i] != src[j]) return false;
		   int dstCount = 1,srcCount = 1;
		   
			// dst[++i] means increment the value of i then use it 
            while(i<dst.size() && dst[i]==dst[++i]) { dstCount++;} 
            while(j<src.size() && src[j]==src[++j]) { srcCount++;}
                  
            if(dstCount != srcCount && (srcCount > dstCount || dstCount <3))
                return false;
        }
        
        return i==dst.size() && j==src.size();
    }
    
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        
        for(auto w : words) {
            res += isExpressive(S,w);
        }
        
        return res;
        
    }
};
class Solution2 {
public:
    int expressiveWords(string S, vector<string>& words) {
    int res = 0;
    for (auto &w : words)
        if (w.size() <= S.size()) {
            int i, j;
            for (i = 0, j = 0; j < S.size(); j++) {
                if (w[i] == S[j]) // w[i] references to a null char when i reaches w.size()
                    i++;
                else if (j > 0 && S[j] == S[j - 1] && j + 1 < S.size() && S[j] == S[j + 1]) // last, this and next
                    j++;
                else if (!(j > 1 && S[j] == S[j - 1] && S[j] == S[j - 2])) // this and last 2 chars
                    break;
            }
            if (i == w.size() && j == S.size()) // both pointers reach the end
                res++;
        }
    return res;
}
};

int main(void)
{
	
	Solution sol;
	Solution2 sol2;
	string S = "heeellooo";
	vector<string> words{"hello", "hi", "helo"};
	
	cout << sol.expressiveWords(S,words) << endl;
	cout << sol2.expressiveWords(S,words) << endl;
	return 0;
}


