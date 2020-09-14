#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int all[6] = {0}, acnt[6] = {0}, bcnt[6] = {0};
        for (int i = 0; i < A.size(); i++) {
            int ia = A[i] - 1;
            int ib = B[i] - 1;
            acnt[ia]++;
            bcnt[ib]++;
            all[ia]++;
            if (A[i] != B[i]) {
                all[ib]++;
            }
        }

        int minv = A.size();
        for (int i = 0; i < 6; i++) {
            if (all[i] < A.size()) {
                continue;
            }
            minv = std::min(minv, all[i] - std::max(acnt[i], bcnt[i]));
        }
        if (minv == A.size()) {
            return -1;
        }
        return minv;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {2,1,2,4,2,2};
    vector<int> v2 = {5,2,6,2,3,2};
    assert(s.minDominoRotations(v1, v2) == 2);

    vector<int> v3 = {3,5,1,2,3};
    vector<int> v4 = {3,6,3,3,4};
    assert(s.minDominoRotations(v3, v4) == -1);
    return 0;
}