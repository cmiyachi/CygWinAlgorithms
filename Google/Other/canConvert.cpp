/* Given two strings str1 and str2 of the same length, determine whether you can transform str1 into str2 by doing zero or more conversions.

In one conversion you can convert all occurrences of one character in str1 to any other lowercase English character.

Return true if and only if you can transform str1 into str2.

 

Example 1:

Input: str1 = "aabcc", str2 = "ccdee"
Output: true
Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that the order of conversions matter.
Example 2:

Input: str1 = "leetcode", str2 = "codeleet"
Output: false
Explanation: There is no way to transform str1 to str2.
 

Note:

1 <= str1.length == str2.length <= 10^4
Both str1 and str2 contain only lowercase English letters. */
class Solution {
public:
    bool canConvert(string str1, string str2) {
        
    }
};

/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool canConvert(string str1, string str2) {

        if(str1 == str2) return true;

        unordered_map<char, char> map;
        for(int i = 0; i < str1.size(); i ++){
            if(map.count(str1[i]) && map[str1[i]] != str2[i])
                return false;
            map[str1[i]] = str2[i];
        }
        return unordered_set<char>(str2.begin(), str2.end()).size() < 26;
    }
};


int main() {

    cout << Solution().canConvert("aabcc", "ccdee") << endl;
    // 1

    cout << Solution().canConvert("leetcode", "codeleet") << endl;
    // 0

    cout << Solution().canConvert("abcde", "zzzzz") << endl;
    // 1

    return 0;
}
