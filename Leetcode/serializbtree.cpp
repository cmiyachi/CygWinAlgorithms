/**
 * Definition for a binary tree node.
 
 */
#include <bits/stdc++.h> 
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
  
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return mydeserialize(data);
    }
    TreeNode* mydeserialize(string& data) {
        if (data[0]=='#') {
            if(data.size() > 1) data = data.substr(2);
            return nullptr;
        } else {
            TreeNode* node = new TreeNode(helper(data));
            node->left = mydeserialize(data);
            node->right = mydeserialize(data);
            return node;
        }
    }
private:
    int helper(string& data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

void printTreeNode(TreeNode *tree)
{
	if (tree == NULL) return; 
	
	cout << tree->val << endl;
	cout << " r and l" << endl;
	printTreeNode(tree->left);
	printTreeNode(tree->right);
	
	return; 
}
int main(void)
{
	TreeNode *testnode = new TreeNode(1);
	testnode->left = new TreeNode(2);
	testnode->right = new TreeNode(3);
	testnode->left->left = new TreeNode(4);
	testnode->left->right = new TreeNode(5);
	testnode->right->left = new TreeNode(6);
	testnode->right->right = new TreeNode(7);
	
	/*
				1
			   / \
			  2	  3
			 / \ /  \
			4   56   7
			*/
		
	Codec codec;
	
	string result = codec.serialize(testnode);
	cout << result << endl;
	
	TreeNode *final = codec.deserialize(result); 
	
	printTreeNode(final); 
	
	return 0;
}