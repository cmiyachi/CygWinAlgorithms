#include <bits/stdc++.h> 
using namespace std; 

//Definition for a binary tree node.
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
    TreeNode* deleteNode(TreeNode* root, int key) {
		
        if (root == NULL) return NULL;

		// delete from the right subtree
		if (key > root->val) root->right = deleteNode(root->right, key);
		// delete from the left subtree
		else if (key < root->val) root->left = deleteNode(root->left, key);
		// delete the current node
		else {
		  // the node is a leaf
		  if (root->left == NULL && root->right == NULL) root = NULL;
		  // the node is not a leaf and has a right child
		  else if (root->right != NULL) {
			root->val = successor(root);
			root->right = deleteNode(root->right, root->val);
		  }
		  // the node is not a leaf, has no right child, and has a left child    
		  else {
			root->val = predecessor(root);
			root->left = deleteNode(root->left, root->val);
		  }
		}
		return root;
	}
	 /*
	One step right and then always left
	*/
	int successor(TreeNode* root) {
		root = root->right;
		while (root->left != NULL) root = root->left;
		return root->val;
	 }
	 /*
	  One step left and then always right
	  */
	 int predecessor(TreeNode* root) {
		root = root->left;
		while (root->right != NULL) root = root->right;
		return root->val;
	  }
};


/*

Algorithm

If key > root.val then delete the node to delete is in the right subtree root.right = deleteNode(root.right, key).

If key < root.val then delete the node to delete is in the left subtree root.left = deleteNode(root.left, key).

If key == root.val then the node to delete is right here. Let's do it :

If the node is a leaf, the delete process is straightforward : root = null.

If the node is not a leaf and has the right child, then replace the node value by a successor value root.val = successor.val, and then recursively delete the successor in the right subtree root.right = deleteNode(root.right, root.val).

If the node is not a leaf and has only the left child, then replace the node value by a predecessor value root.val = predecessor.val, and then recursively delete the predecessor in the left subtree root.left = deleteNode(root.left, root.val).

Return root.

*/



class SolutionNotABST {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key) {
            if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else {
                TreeNode* right = root->right;
                while (right->left)
                    right = right->left;
                swap(root->val, right->val);    
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};