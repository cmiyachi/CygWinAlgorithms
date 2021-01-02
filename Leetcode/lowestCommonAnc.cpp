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

// Driver program to test above functions 
int main() 
{ 
	// Let us create the Binary Tree shown in above diagram. 
	TreeNode * root = new TreeNode(1); 
	root->left = new TreeNode(2); 
	root->right = new TreeNode(3); 
	root->left->left = new TreeNode(4); 
	root->left->right = new TreeNode(5); 
	root->right->left = new TreeNode(6); 
	root->right->right = new TreeNode(7); 
	
	
	TreeNode *temp = lca(root, 4, 5);
	cout << temp->data << endl;
	temp = lca(root, 4, 6);
	cout << temp->data << endl;
	temp = lca(root, 3, 4);
	cout << temp->data << endl;
	temp = lca(root, 2, 4);	
	cout << temp->data << endl;

	return 0; 
} 
