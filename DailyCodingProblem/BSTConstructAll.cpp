#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  vector<TreeNode*> construct_BST(int l,int h)//l:min value in the left, h:max value in the right
    {
        vector<TreeNode*> res;
     
        if(l>h)
        {
            res.push_back(nullptr);
            return res;
        }
        
    
        for(int i=l;i<=h;i++)// select the root
        {
            //when l==h
            //lefts={nullptr} rights={nullptr} 
            vector<TreeNode*> lefts=construct_BST(l,i-1);  //get all possible left node
            vector<TreeNode*> rights=construct_BST(i+1,h);//get all possible right node
            
            //combine: O(n^2)
            for(int j=0;j<lefts.size();j++)
            {
                for(int k=0;k<rights.size();k++)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=lefts[j];
                    root->right=rights[k];
                    res.push_back(root);
                }
            }
            
        }
        return res;//return all possible node from l to h
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        if(n==0)
            return vector<TreeNode*>(0);
        return construct_BST(1,n);
             
    }
	void printTree(TreeNode *root)
	{
		if (root == NULL) return;
		
		
		cout << "l ";
		printTree(root->left);
		cout << "t " << root->val << endl;
		cout << "r "; 
		printTree(root->right);
		
		return;
	}
	vector<int> preorder(TreeNode* root)
	{
		vector<int> result;
		
		if (root != NULL)
		{
			result.push_back(root->val);
			vector<int> ltmp = preorder(root->left);
			result.insert(result.end(), ltmp.begin(), ltmp.end());
			
			vector<int> rtmp =  preorder(root->right); 
			result.insert(result.end(), rtmp.begin(), rtmp.end());
		}
		
		return result; 
	}
	int main(void)
	{
		vector<TreeNode*> result = generateTrees(3);
		
		for (TreeNode* tree : result)
		{
			cout << "************" << endl;
			printTree(tree);
			cout << endl;
		}
		for (TreeNode* tree : result)
		{
			vector<int> preTree = preorder(tree);
			for (int x : preTree)
				cout << x << " ";
			cout << endl;
		}
		
		return 0;
	}