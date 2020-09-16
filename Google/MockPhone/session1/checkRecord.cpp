class Solution {
public:
    bool checkRecord(const std::string& s) {
        int num_As = 0, num_consecutive_Ls = 0;
        for (auto ch: s) {
            if (ch == 'A') {
                ++num_As;
                num_consecutive_Ls = 0;
            } else if (ch == 'L') {
                ++num_consecutive_Ls;
            } else if (ch == 'P') {
                num_consecutive_Ls = 0;
            }
            if (num_As > 1 || num_consecutive_Ls > 2) { return false; }
        }
        return true;
    }
};