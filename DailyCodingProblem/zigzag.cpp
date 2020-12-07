#include <bits/stdc++.h>
using namespace std;

  vector<string> zigZag(string s, int k) {
        /**
         * Idea - iterate in chunks of k size, each iteration changes from top-down to bottom-up. On each step save
         * last element of previously visited chunk, then skip it on the next iteration. For the result - create
         * array of k empty char arrays, initiallize with ' '. Set proper character from String at correct position
         */
        if (s.length() == 0)
            return vector<string>{};

        int N = s.length();
        k = min(N, k);
		vector<vector<char>> arr(k,vector<char>(N, ' ')); 
  
        int prev = -1;
        bool down = true;
        for (int i = 0; i < N; i += (k - 1)) {
            int j = i;
            int kk;
            if (down) {
                kk = 0;
                for (; j < i + k  && j < N; j++) {
                    if (j == prev) {
                        kk++;
                    } else {
                        arr[kk++][j] = s[j];
                    }
                }
            } else {
                kk = k - 1;
                for (; j < i + k  && j < N; j++) {
                    if (j == prev) {
                        kk--;
                    } else {
                        arr[kk--][j] = s[j];
                    }
                }
            }
            prev = j - 1;
            down = !down;
        }
		
		vector<string> res;
        for (vector<char> c : arr) {
            string str(c.begin(), c.end());
            res.push_back(str);
        }
        return res;
    }
	
	
	int main(void)
	{
		string s = "thisisazigzag";
		int k = 4;
		
		vector<string> result = zigZag(s,k);
		
		for (string ss : result)
			cout << ss << endl;
			
		return 0;
	}
