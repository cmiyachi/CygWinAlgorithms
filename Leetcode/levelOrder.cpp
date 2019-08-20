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
 
class Solution2 {
public:
	vector<vector<int>> levels; 
		
	void helper(TreeNode *node, int level)
	{
		vector<int> this_level;
		if (levels.size() == level)
		{
			levels.push_back(this_level); 
		}
		//else
		//	this_level = levels[level];
		
		levels[level].push_back(node->val);
		
		if (node->left != NULL)
			helper(node->left, level+1);
		if (node->right != NULL)
			helper(node->right, level+1);
		
	} // helper
    vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return levels; 
		helper(root, 0); 
		return levels;
    }
};

class Solution {
public:
	
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> levels; 
		if (root == NULL) return levels; 
		queue<TreeNode*> queue; 
		queue.push(root); 
		int level = 0; 
		 
		while (!queue.empty())
		{
			vector<int> this_level; 
			levels.push_back(this_level); 
			int level_length = queue.size(); 
			for (int i = 0; i < level_length; i++)
			{
				TreeNode *node = queue.front(); queue.pop(); 
				levels[level].push_back(node->val); 
				
				if (node->left != NULL) queue.push(node->left); 
				if (node->right != NULL) queue.push(node->right); 
			}  // for
			level++;
		} // while
		
		return levels;
    }
};

int main(void)
{
	TreeNode* a = new TreeNode(3); 
	a->left = new TreeNode(9);
	a->right = new TreeNode(20);
	a->right->right = new TreeNode(7);
	a->right->left = new TreeNode(15);
	
	Solution sol;
	
	vector<vector<int>> result = sol.levelOrder(a);
	for (int i = 0; i < result.size(); i++) {
		cout << "["; 
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << ",";
		cout << "] "; 
	}
	
	return 0;
}