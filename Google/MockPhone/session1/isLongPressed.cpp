class Solution {
public:
    bool isLongPressedName(string& name, string& typed) {
        if (typed.length() < name.length()) return false;
        int i = 0;
        int j = 0;
        while (i < name.length() && j < typed.length()) {
            if (name[i] == typed[j]) {
                ++i;
                ++j;
            } else {
                if ((j > 0) && (typed[j-1] == typed[j])) {
                    ++j;
                } else {
                    return false;
                }
            }
        }
        if (i != name.length()) return false;
        while ((j > 0) && (j < typed.length()) && typed[j] == typed[j-1]) ++j;
        return j == typed.length();
    }
};