#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int h1 = 0,h2 = 0;
        TreeNode* l = root;
        TreeNode* r = root;

        while (l){
            h1++;
            l = l->left;
        }
        while (r){
            h2++;
            r = r->right;
        }
        if(h1==h2) return pow(2,h1)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};

class Solution2 {
private:
    int leftDepth(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int depth = 1;
        while (node->left != nullptr) {
            depth++;
            node = node->left;
        }
        return depth;
    }

    int rightDepth(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int depth = 1;
        while (node->right != nullptr) {
            depth++;
            node = node->right;
        }
        return depth;
    }

    int leftCNodes(TreeNode *left, int ld) {
        int rd = rightDepth(left);
        if (rd == ld) {
            return (1 << (unsigned) ld) - 1;
        } else {
            return 1 + leftCNodes(left->left, ld - 1) + countNodes(left->right);
        }
    }

public:
    int countNodes(TreeNode *root) {
        int ld = leftDepth(root);
        int rd = rightDepth(root);
        if (ld == rd) {
            return (1 << (unsigned) ld) - 1;
        } else {
            return 1 + leftCNodes(root->left, ld - 1) + countNodes(root->right);
        }
    }
};
