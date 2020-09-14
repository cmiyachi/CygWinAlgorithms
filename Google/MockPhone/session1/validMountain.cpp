#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        bool up = true;
        int top = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1]) {
                if (up) {
                    top++;
                } else {
                    return false;
                }
            } else if (A[i] == A[i - 1]) {
                return false;
            } else {
                if (up) {
                    up = false;
                }
            }
        }
        return top > 0 && top < A.size() - 1;
    }
};

int main(void) {
    Solution s;
    vector<int> v1 = {2,1};
    cout << (s.validMountainArray(v1)) << endl;
    vector<int> v2 = {1,2,3};
    cout << (s.validMountainArray(v2))<< endl;
    vector<int> v3 = {3,5,5};
    cout << (s.validMountainArray(v3))<< endl;
    vector<int> v4 = {0,3,2,1};
    cout << (s.validMountainArray(v4))<< endl;
    return 0;
}