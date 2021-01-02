/// https://leetcode.com/problems/symmetric-tree/
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
    bool helper(TreeNode *leftTree,TreeNode* rightTree){
        if(leftTree==NULL && rightTree!=NULL) return false;
        if(leftTree!=NULL && rightTree==NULL) return false;
        if(leftTree==NULL && rightTree==NULL) return true;
        
        if(leftTree->val != rightTree->val) return false;
        
        
        return helper(leftTree->left,rightTree->right) &&
               helper(leftTree->right,rightTree->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        
        return helper(root->left,root->right);
    
    }
};

class Solution2 {
public:
    bool isSymmetricUtil(TreeNode * left, TreeNode * right){
        if(left == NULL || right == NULL)
            return (left == right);
        
        return (left->val == right->val) &&(isSymmetricUtil(left->left,right->right) && isSymmetricUtil(left->right,right->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isSymmetricUtil(root->left,root->right);
    }
};

    // bottom-up recursive approach
//     bool dfs(TreeNode* l, TreeNode* r) {
//         if(!l && !r) return true;
//         else if((!l && r) || (!r && l)) return false;
        
//         bool res1 = dfs(l->left, r->right);
//         bool res2 = dfs(l->right, r->left);
//         if(l->val != r->val) return false;
//         else return res1 && res2;
//     }
    
//     bool isSymmetric(TreeNode* root) {
//         if(!root || (!root->left && !root->right)) return true;
//         return dfs(root->left, root->right);
//     }
    
    bool isSymmetric(TreeNode* root) {
        
        if(!root || (!root->left && !root->right)) return true;
        
        deque<TreeNode*> s1;
        if(root->left) s1.push_back(root->left);
        deque<TreeNode*> s2;
        if(root->right) s2.push_back(root->right);
        
        while(!s1.empty() && !s2.empty()) {
            
            TreeNode* l = s1.front(); s1.pop_front();
            TreeNode* r = s2.front(); s2.pop_front();
            if(l->val != r->val) return false;
            if(l->left) s1.push_back(l->left);
            if(r->right) s2.push_back(r->right);
            if(s1.size() != s2.size()) return false;
            
            if(l->right) s1.push_back(l->right);
            if(r->left) s2.push_back(r->left);
            if(s1.size() != s2.size()) return false;
        }
        if((!s1.empty() && s2.empty()) || (s1.empty() && !s2.empty())) return false;
        return true;
    }
};