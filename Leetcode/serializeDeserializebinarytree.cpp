 #include <bits/stdc++.h> 
using namespace std;

 // Definition for a binary tree node.
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
        stringstream out;
        serialize(root,out);
        return out.str();       
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    { 
        stringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode* root,stringstream &out)
    {
        if(root)
        {
            out<<root->val<<" ";
            serialize(root->left,out);
            serialize(root->right,out);
        }
        else
        {
            out<<"# ";
        }
    }

    TreeNode* deserialize(stringstream &in)
    {
        string val;
        in>>val;

        if(val=="#")
        return nullptr;
        TreeNode* root= new TreeNode(stoi(val));
        root->left=deserialize(in);
        root->right=deserialize(in);
        return root;
    }
}; 
 
class Codec2 {

public:
 stringstream* postorder(TreeNode *root, stringstream* sb) {
    if (root == NULL) return sb;
    postorder(root->left, sb);
    postorder(root->right, sb);
    *sb << root->val;
    *sb << ' ';
    return sb;
  }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		stringstream s;
        stringstream *sb = postorder(root, &s);
		string result = sb->str(); 
		result.pop_back(); 
		return result;
    }

	TreeNode* helper(int lower, int upper, deque<int> nums) {
    if (nums.empty()) return NULL;
    int val = nums.back();
    if (val < lower || val > upper) return NULL;

    nums.pop_back();
    TreeNode *root = new TreeNode(val);
    root->right = helper(val, upper, nums);
    root->left = helper(lower, val, nums);
    return root;
  }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
		deque<int> nums;
		istringstream iss(data);
		do {
			string subs; 
			iss >> subs;
			int x; 
			sscanf(subs.c_str(), "%d", &x); 
			nums.push_back(x); 
		}while (iss);
		return helper(INT_MIN, INT_MAX, nums);
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