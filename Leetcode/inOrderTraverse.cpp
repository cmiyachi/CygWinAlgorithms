/// https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    
    void inorder(TreeNode* root, vector<int> &ans){
        if(root==NULL) return;
        
        inorder(root->left,ans);   // left
        ans.push_back(root->val);       // data
        inorder(root->right,ans);   // right
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};


class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        helper(root, res);
        return res; 
    }
    
    void helper(TreeNode *node, vector<int> &res)
    {
        if (node != NULL)
        {
            if (node->left != NULL)
                helper(node->left,res);
            res.push_back(node->val);
            if (node->right != NULL)
                helper(node->right, res);
        }
    }
};

class Solution3{
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            
            vector<int> res;
            stack<TreeNode *> nodes;
         //   if (root == NULL) return res; 
            
            TreeNode *current = root;
         //   nodes.push(current); 
            
            while ((current != NULL) || !nodes.empty())
            {
                while (current != NULL)
                {
                    nodes.push(current);
                    current = current->left; 
                }
                current = nodes.top(); nodes.pop();
                res.push_back(current->val);
                current = current->right; 
            }
            return res; 
    }
    

};