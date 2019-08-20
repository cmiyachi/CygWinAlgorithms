
#include <bits/stdc++.h> 
using namespace std;
/**
 * Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
		map<int, int> rightmostValueAtDepth; 
		int max_depth = -1; 
		/* These two stacks are always synchronized, providing an implicit
         * association values with the same offset on each stack. */
		 stack<TreeNode*> nodeStack; 
		 stack<int> depthStack; 
		 nodeStack.push(root);
		 depthStack.push(0); 
		while(!nodeStack.empty())
		{
			TreeNode* node = nodeStack.top();  nodeStack.pop();
			int depth = depthStack.top(); depthStack.pop(); 
			
			if (node != NULL)
			{
				max_depth = max(max_depth,depth); 
				 /* The first node that we encounter at a particular depth contains
                * the correct value. */
				  if (rightmostValueAtDepth.find(depth) == rightmostValueAtDepth.end() ) {
                    rightmostValueAtDepth[depth] = node->val;
                }
				
				nodeStack.push(node->left);
                nodeStack.push(node->right);
                depthStack.push(depth+1);
                depthStack.push(depth+1);
				
			} // if
			
		} // while
	
        vector<int> rightView;
        for (int depth = 0; depth <= max_depth; depth++) {
            rightView.push_back(rightmostValueAtDepth[depth]);
        }

        return rightView;
    } // function
};

/*
					3
				5    	1
			6	  2   0    8
			    7   4
				*/

int main () {
    TreeNode* r = new TreeNode(3);
    r->left = new TreeNode(5);
    r->right = new TreeNode(1);

    r->left->left = new TreeNode(6);
    r->left->right = new TreeNode(2);

    r->left->right->left = new TreeNode(7);
    r->left->right->right = new TreeNode(4);

    r->right->left = new TreeNode(0);
    r->right->right = new TreeNode(8);
	
	Solution sol;
	
	vector<int> result = sol.rightSideView(r);
	
	for (int i = 0; i < result.size(); i++)
		cout <<  result[i] << " , "; 

    Solution s;
   
    return 0;
}

