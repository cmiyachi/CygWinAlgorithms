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
  
  
  TreeNode* helper(vector<int>& nums,int start,int end)
    {
        if(start>end) //nullptr
            return nullptr;
        else if(start==end)
            return new TreeNode(nums[start]); //just one node,just the node
        else{
            int mid=(start+end)/2;
            TreeNode* root=new TreeNode(nums[mid]);
            
            root->left=helper(nums,start,mid-1); //left
            root->right=helper(nums,mid+1,end); //right
            return root;
        }
    }
TreeNode*fun(vector<int>nums,int s, int e){
        if(s>e) return NULL;
        if(s<=e){
            int m=((s+e)/2);
            TreeNode*root=new TreeNode(nums[m]);
            root->left=fun(nums,s,m-1);
            root->right=fun(nums,m+1,e);
            return root;
        }
      return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
          int s=0;
          int e=nums.size()-1;
		  return helper(nums,s,e);
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
	
	int main(void)
	{
		vector<int> nums{-10,-3,0,5,9};
		
		TreeNode *root = sortedArrayToBST(nums);
		
		printTree(root);
		return 0;
	}