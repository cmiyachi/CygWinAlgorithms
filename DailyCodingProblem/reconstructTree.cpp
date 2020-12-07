#include <bits/stdc++.h>
using namespace std;


  struct TreeNode {
      char val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(' '), left(nullptr), right(nullptr) {}
		TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
     // TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right);
  };
  
  
  TreeNode *reconstructTree(vector<char> preorder, vector<char> inorder)
  {
	  if (preorder.size() == 0 && inorder.size() == 0) return NULL;
	  
	  if (preorder.size() == 1 && inorder.size() == 1) 
	  {	
			TreeNode *n = new TreeNode(preorder[0]);
			return n;
	  }
	  
	  TreeNode *root = new TreeNode(preorder[0]); 
	  
	  auto it = find(inorder.begin(), inorder.end(), root->val);
 
    // If element was found
  //  if (it != v.end()) 
     
        // calculating the index
        // of K
      int index = it - inorder.begin();
	  vector<char> v1{preorder.begin()+1, preorder.begin()+1+index};
	  vector<char> v2{inorder.begin(), inorder.begin()+index};
	  root->left = reconstructTree(v1, v2);
	  vector<char> v3{preorder.begin()+1+index, preorder.end()};
	  vector<char> v4{inorder.begin()+1+index, inorder.end()};
	  root->right = reconstructTree(v3, v4);
	  
	  return root;
  }
  
  void printTree(TreeNode *root)
  {
	  if (root == NULL) return;
	  
	  cout << root->val << " ";
	  cout << "R ";
	  printTree(root->right);
	  cout << "L "; 
	  printTree(root->left);
	  cout << endl; 
  }
	  
  
  int main(void)
  {
	  
	  vector<char> preorder{'a','b','d','e','c','f','g'};
	  vector<char> inorder{'d','b','e','a','f','c','g'};
	  
	  TreeNode *root = reconstructTree(preorder, inorder);
	  
	  printTree(root);
	  
	  return 0;
  }
	  
	 
		  
	  
	  