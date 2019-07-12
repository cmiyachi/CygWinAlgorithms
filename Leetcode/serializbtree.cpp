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
		string result; 
		if (root == NULL)
			result += "null,"; 
		else{
			int x = root->val; 
			
			result += x.to_string() + ","; 
			result += serialize(root->left);
			result += serialize(root->right);
		}
		
        return result; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		// split the string
		std::vector<string> nodes;
		std::stringstream ss(data);

		while( ss.good() )
		{
			string substr;
			getline( ss, substr, ',' );
			nodes.push_back( substr );
		}
		
		if (nodes[0] == "null") {
			nodes.erase(nodes.begin()); 
			return NULL;
		}
		
		int x; 
		sscanf(nodes[0], "%d", &x); 
		string whatsleft; 
		TreeNode *root = new TreeNode(x);
		nodes.erase(nodes.begin());
		for (int i = 0; i < nodes.size(); i++)
			whatsleft += 
		root->left = deserialize(root);
		root->right = deserialize(root);
		
		return root; 
			
			
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