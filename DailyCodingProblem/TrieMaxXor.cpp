#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* next[2];
    
    TrieNode() {
        memset(next, 0, sizeof(next));
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ret = 0;
        
        TrieNode* root = new TrieNode();
        
        for(int i : nums) {
            insert(root, i);
        }

        for(int i : nums) {
            int x = findMax(root, i);
            ret = max(ret, x);
        }
        
        return ret;
    }

private:
    void insert(TrieNode* root, int n) {
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (n & (1<<i));
            if(bit) {
                // in i position (...1...) is 1
                bit = 1;
            }
            if(node->next[bit] == nullptr) {
                node->next[bit] = new TrieNode();
            }
            node = node->next[bit];
        }
    }
    
    int findMax(TrieNode* root, int n) {
        int ret = 0;
        TrieNode* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (n & (1<<i));
            if(bit) bit = 1;
            if(node->next[!bit]) { // xor
                ret += (1<<i);
                node = node->next[!bit];
            } else {
                node = node->next[bit];
            }
        }
        
        return ret;
    }
};

int main(void)
{
	
	vector<int> nums{3,10,5,25,8};
	Solution sol;
	cout << sol.findMaximumXOR(nums) << endl;
	
	vector<int> nums2{4,6,7};
	Solution sol2;
	cout << sol2.findMaximumXOR(nums2) << endl;
	
	return 0;
}