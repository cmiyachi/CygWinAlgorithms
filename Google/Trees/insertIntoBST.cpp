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
    TreeNode* insertIntoBST(TreeNode *node, int val) {
		if (!node) {
			TreeNode *newNode = new TreeNode(val);
			return newNode;
		}
		if (val < node->val) {
			node->left = insertIntoBST(node->left, val);
		}
		else {
			node->right = insertIntoBST(node->right, val);
		}
		return node;
	}
};

//Starting from root, each time move to the left or right child. Once we reach a leaf node, insert val.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *cur = root, *node = new TreeNode(val);
        while (cur) {
            if (cur -> val > val) {
                if (cur -> left) {
                    cur = cur -> left;
                } else {
                    cur -> left = node;
                    break;
                }
            } else {
                if (cur -> right) {
                    cur = cur -> right;
                } else {
                    cur -> right = node;
                    break;
                }
            }
        }
        return root ? root : node;
    }
};