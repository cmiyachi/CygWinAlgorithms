/// https://leetcode.com/problems/invert-binary-tree/
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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        
        swap(root->left,root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        
        return root;
    }
};

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        //find a leaf
        // if node->left->left and right == NULL then you are at a leaf
        // swap leafs
    
        invertTreeRecursive(root); 
        
        return root; 
    }
    
    void invertTreeRecursive(TreeNode *node)
    {
        if (node == NULL) return; 
        
        TreeNode *temp = node->right; 
        node->right = node->left; 
        node->left = temp; 
        
        invertTreeRecursive(node->right);
        invertTreeRecursive(node->left);
        
    }
};