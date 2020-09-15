// Brute Force: Iterate the flowers array (for days 1,2,...N), switching flowers into bloom and 
// checking k flowers away. O(n*k)
// Better: Build the reverse mapping from flowers -> bloom day, then iterate flowers 1...N
// maintaining an interval (left_flower, right_flower) and bloom days (left_day, right_day).
// If the i'th flower blooms before left_day or right_day, then the interval is reset. O(n) time and space.

#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
#include <ctime>
#include <assert.h>

// Accepted. 199ms. Beats 79.86% of submissions, ties 4.66% of submissions.
class Solution {
public:
    int kEmptySlots(const std::vector<int>& flowers, int k) {
        if (flowers.size() < k+2) { return -1; }

        int days[flowers.size()+1] = {0};
        for (int i = 0; i < flowers.size(); ++i) {
            days[flowers[i]] = i+1;
        }

        bool found = false;
        int best_day1 = std::numeric_limits<int>::max(), best_day2 = std::numeric_limits<int>::max();
        int left_flower = 1, left_day = days[left_flower];
        int right_flower = left_flower + k + 1, right_day = days[right_flower];
        for (int flower = 2; flower <= flowers.size(); ++flower) {
            int day = days[flower];

            if (flower == right_flower) {
                if (std::max(left_day, right_day) < std::max(best_day1, best_day2)) {
                    best_day1 = left_day;
                    best_day2 = right_day;
                    found = true;
                }
                left_flower = flower;
                left_day = day;
                right_flower = left_flower + k + 1;
                if (right_flower > flowers.size()) { break; }
                right_day = days[right_flower];
            } else if (day < left_day || day < right_day) {
                left_flower = flower;
                left_day = day;
                right_flower = left_flower + k + 1;
                if (right_flower > flowers.size()) { break; }
                right_day = days[right_flower];
            }
        }
        return found ? std::max(best_day1, best_day2) : -1;
    }
};

 int kEmptySlots(vector<int> &flowers, int k) {
        vector<int> days(flowers.size());
        for (int i = 0; i < flowers.size(); ++i)
            days[flowers[i] - 1] = i + 1;
        int left = 0, right = left + k + 1, res = INT_MAX;
        for (int i = 0; i < flowers.size(); ++i) {
            if (i == right) {
                res = min(res, max(days[left], days[right]));
                left = i;
                right = left + k + 1;
            } else if (days[left] > days[i] || days[i] < days[right]) {
                left = i;
                right = left + k + 1;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    vector<int> flowers = {1, 2, 3};

    Solution s;
    cout << s.kEmptySlots(flowers, 1) << endl;
    return 0;
}