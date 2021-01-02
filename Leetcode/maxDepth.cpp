/// https://leetcode.com/problems/maximum-depth-of-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        /// maxDepth = height
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return max(left,right) + 1;
    }
};


class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        return 0;
        
    }
};

class Solution3 {
  public:
    int maxDepth(TreeNode *root) {
      if (root == NULL) {
        return 0;
      }
      return max(1 + maxDepth(root -> left), 1 + maxDepth(root -> right));
    }
};