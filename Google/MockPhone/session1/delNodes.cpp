

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* delNodes(TreeNode* root, unordered_set<int>& to_del, vector<TreeNode*>& res) {
      if (root != nullptr) {
        root->left = delNodes(root->left, to_del, res);
        root->right = delNodes(root->right, to_del, res);
        if (to_del.find(root->val) != end(to_del)) {
          if (root->left != nullptr) res.push_back(root->left);
          if (root->right != nullptr) res.push_back(root->right);
          root = nullptr;
        }
      }
      return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_del) {
      vector<TreeNode*> res;
      root = delNodes(root, unordered_set<int>() = unordered_set<int>(begin(to_del), end(to_del)), res);
      if (root != nullptr) res.push_back(root);
      return res;
    }
};