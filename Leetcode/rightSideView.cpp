
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
T = O(n) & S = O(n) due to queue
stepwise
1. declare a vector storing int values
2. declare a queue storing node type value(TreeNode*)
3. push root into queue
4. work until queue is not empty
5. iterate until last element present in queue and push last element of current queue size
6. check for left and right node if null or not
7. Repeat steps from 4 to 6
8. return the vector.
*/
vector<int> rightSideView(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<int> v; //store values of nodes in the rightmost
        queue<TreeNode*> Q; //store node type values in queue 
        Q.push(root); //push root
        while(!Q.empty()) { //repeat steps until queue is not empty
            
            int size = Q.size();  // current size of queue
            for(int i = 0; i < size; i++) {
              TreeNode* t = Q.front(); //declare a temp node and put front node of queue
                Q.pop(); 
                if(i==size-1) {   //if node is rightmost 
                    v.push_back(t->val); //push the value of rightmost node into vector
                }
                if(t->left) {   //if temp->left != NULL then push into queue
                    Q.push(t->left);
                }
                if(t->right) { //if temp->right != NULL then push into queue
                    Q.push(t->right);
                }
            }  
        }
        return v; //finally we have all values
    }
	
	
	class Solutiondfs {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxdepth = -1;
        helper(root, 0, maxdepth, ans);
        return ans;
    }
    
    void helper(TreeNode*root, int depth, int& maxdepth, vector<int>& ans){
        if(!root)return;
        if(depth>maxdepth){
            maxdepth = depth;
            ans.push_back(root->val);
        }
        
        helper(root->right,depth+1,maxdepth,ans);
        helper(root->left,depth+1,maxdepth,ans);
    }
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

