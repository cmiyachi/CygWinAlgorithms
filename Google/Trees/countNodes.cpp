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
 
 /**  JAVA 
 
 class Solution {
  public int countNodes(TreeNode root) {
    return root != null ? 1 + countNodes(root.right) + countNodes(root.left) : 0;
  }
}
**/
class Solution2 {

public:

    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int hl=0, hr=0;

        TreeNode *l=root, *r=root;

        while(l) {hl++;l=l->left;}

        while(r) {hr++;r=r->right;}

        if(hl==hr) return pow(2,hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);

    }

};
class Solution {
public:
    int getLeftHeight(TreeNode* root) {
		int height = 0;
		while(root) { 
			root = root->left;
			height++;
		}
		return height;
	}

	int countNodes(TreeNode* root) {
		if(!root) return 0;
		
		int left_height = getLeftHeight(root->left);
		int right_height = getLeftHeight(root->right);
		
		if(left_height == right_height) 
			return pow(2, left_height) + countNodes(root->right);
			
		return pow(2, right_height) + countNodes(root->left);
	}
};