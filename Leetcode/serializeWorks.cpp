
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

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if(root) {
            out << root->val << " ";
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "#" << " ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if(val == "#") {
            return nullptr;
        } else {
            TreeNode* node = new TreeNode(stoi(val));
            node->left = deserialize(in);
            node->right = deserialize(in);
            return node;
        }
    }
};


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