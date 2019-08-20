#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
class Solution {
    private: int sum = 0;
public: 
	TreeNode* convertBST(TreeNode* root) {
        if (root != NULL) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};
/*
class Solution {
    public TreeNode convertBST(TreeNode root) {
        int sum = 0;
        TreeNode node = root;
        Stack<TreeNode> stack = new Stack<TreeNode>();

        while (!stack.isEmpty() || node != null) {
            /* push all nodes up to (and including) this subtree's maximum on
             * the stack. 
            while (node != null) {
                stack.add(node);
                node = node.right;
            }

            node = stack.pop();
            sum += node.val;
            node.val = sum;

            /* all nodes with values between the current and its parent lie in
             * the left subtree. 
           node = node.left;
        }

        return root;
    }
}*/

int main () {
    TreeNode* r = new TreeNode(5);
    r->left = new TreeNode(2);
    r->right = new TreeNode(13);

    Solution s;
    TreeNode* p = s.convertBST(r); // 2,8
	cout << p->val << endl;
	cout << p->left->val << " " << p->right->val; 
	
	return 0;
}