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
    class Result
    {   public:
        int count; 
        bool unival; 
    };
    
    int countUnivalSubtrees(TreeNode* root) {
        
        int ans = 0;
        
        Result r = helper(root);
        
        ans = r.count; 
        
      //  dfs (root, ans);
        
        return ans;
    }
    
    void dfs(TreeNode* root, int& ans)
    {
        if (!root) return;
        
        if (subTree(root->left,  root->val) && subTree(root->right, root->val)) ans++;
        
        dfs(root->left,  ans);
        dfs(root->right, ans);
    }
    
    bool subTree(TreeNode* root, int val)
    {
        if (!root) return true;
        
        if (root->val != val) return false;
        
        return subTree(root->left, root->val) && subTree(root->right, root->val);
    }
    
    Result  helper(TreeNode* root)
    {
        Result r;
       r.count = 0; r.unival=true;
        if (!root) return r; 
       
       Result rl = helper(root->left);
       Result rr = helper(root->right); 
       int total_count = rl.count + rr.count; 
       
       if (rl.unival && rr.unival)
       {
          if (root->left != NULL && root->val != root->left->val)
          {
              r.count = total_count;
              r.unival = false;
              return r; 
          }
          if (root->right != NULL && root->val != root->right->val)
          {
              r.count = total_count;
              r.unival = false;
              return r; 
          }
          r.count = total_count+1; 
           r.unival = true; 
           return r; 
       }
       
       r.count = total_count;
       r.unival = false;
       return r;
   }

};