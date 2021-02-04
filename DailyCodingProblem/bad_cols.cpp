
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for (int c = 0; c < strs[0].size(); ++c)
            for (int r = 0; r < strs.size() - 1; ++r)
                if (strs[r][c] > strs[r+1][c]) {
                    ans++;
                    break;
                }

        return ans;
        
    }
};
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        
          int N = A.size();
        int W = A[0].size();
        int ans = 0;

        // cur : all rows we have written
        // For example, with A = ["abc","def","ghi"] we might have
        // cur = ["ab", "de", "gh"].
        vector<string> cur(N); 
        for (int j = 0; j < W; ++j) {
            // cur2 : What we potentially can write, including the
            //        newest column col = [A[i][j] for i]
            // Eg. if cur = ["ab","de","gh"] and col = ("c","f","i"),
            // then cur2 = ["abc","def","ghi"].
            vector<string> cur2 = cur; 
            for (int i = 0; i < N; ++i)
                cur2[i] += A[i][j];

            if (isSorted(cur2))
                cur = cur2;
            else
                ans++;
        }

        return ans;
    }

    bool isSorted(vector<string> A) {
        for (int i = 0; i < A.size() - 1; ++i)
            if (A[i] >  A[i+1])
                return false;

        return true;
    }

};