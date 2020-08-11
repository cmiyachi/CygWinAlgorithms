#include<bits/stdc++.h> 
using namespace std;

/**
 * Definition for a binary tree node. */
 
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* node, int& diameter) {
        if (!node) {
            return 0;
        }
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
};

int main(void)
{
	TreeNode *four = new TreeNode(4);
	TreeNode *five = new TreeNode(5);
	TreeNode *two = new TreeNode(2, four, five); 
	TreeNode *three = new TreeNode(3);
	TreeNode *one = new TreeNode(1, two, three);
	
	Solution sol; 
	
	cout << sol.diameterOfBinaryTree(one); 
	
	return 0;
}