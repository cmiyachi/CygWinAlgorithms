/// https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
    struct qItem{
        TreeNode *node;
        int depth;
    };
    
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<qItem> q;
        qItem qi = {root,1};
        q.push(qi);
        
        while(!q.empty()){
            qItem f = q.front();
            q.pop();
            
            TreeNode *node = f.node;
            int depth = f.depth;
            
            /// leaf node
            if(node->left==NULL && node->right==NULL) return depth;
            
            if(node->left){
                qItem a = {node->left,depth+1};
                q.push(a);
            }
            if(node->right){
                qItem a = {node->right,depth+1};
                q.push(a);
            }
        }
        return 0;  /// never get executed , compilation purpose
    }
};