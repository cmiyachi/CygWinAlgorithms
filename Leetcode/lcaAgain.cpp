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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// Value of current node or parent node.
        int parentVal = root->val;

        // Value of p
        int pVal = p->val;

        // Value of q;
        int qVal = q->val;

        if (pVal > parentVal && qVal > parentVal) {
            // If both p and q are greater than parent
            return lowestCommonAncestor(root->right, p, q);
        } else if (pVal < parentVal && qVal < parentVal) {
            // If both p and q are lesser than parent
            return lowestCommonAncestor(root->left, p, q);
        } else {
            // We have found the split point, i.e. the LCA node.
            return root;
        }
        
    }
};
int main () {
    TreeNode* r = new TreeNode(6);
    r->left = new TreeNode(2);
    r->right = new TreeNode(8);

    r->left->left = new TreeNode(0);
    r->left->right = new TreeNode(4);

    r->left->right->left = new TreeNode(3);
    r->left->right->right = new TreeNode(5);

    r->right->left = new TreeNode(7);
    r->right->right = new TreeNode(9);

    Solution s;
    TreeNode* p = s.lowestCommonAncestor(r, r->left, r->right); // 2,8
    assert (p == r); // 6
	cout << p->val << endl; 
    /* p = s.lowestCommonAncestor(r, r->left->left, r->left->right->left);  // 6, 7
    assert (p == r->left); // 5
    p = s.lowestCommonAncestor(r, r->left->left, r->right->right);  // 6, 8
    assert (p == r); // 3
    p = s.lowestCommonAncestor(r, r->right, r->right->right);  // 1, 8
    assert (p == r->right); // 1 */
    return 1;
}