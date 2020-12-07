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

 

    int minLevelSum(TreeNode* root) {
        int res = 0, level = 0;
        int sum = INT_MAX;        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            level++;
            int size = q.size();
            int curSum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                curSum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);          
            }
            if(curSum < sum){
                res = level;
                sum = curSum;
            }       
        }
        return res;
    }
	
	void helper(TreeNode * cur, int level, unordered_map<int, int> & m)
    {
        if(cur == nullptr)
            return;
        m[level] += cur->val;
        helper(cur->left, level +1, m);
        helper(cur->right, level +1, m);
    }
    int maxLevelSum(TreeNode* root) {
        unordered_map<int , int> m;
        helper(root, 1, m);
        
        int max = 0;
        int max_level = 1;
        for(auto it = m.begin(); it != m.end(); it++)
        {
            if(it -> second < max)
            {
                max = it->second;
                max_level = it->first;
            }
        }
        return max_level;
    }
	
	int main(void)
	{
		TreeNode *one = new TreeNode(1);
		TreeNode *two = new TreeNode(2);
		TreeNode *three = new TreeNode(3);
		TreeNode *four = new TreeNode(4);
		TreeNode *five = new TreeNode(5);
		
		one->left = two;
		one->right = three;
		three->left = four; 
		three->right = five; 
		
		cout << minLevelSum(one) << endl;
		
		cout << maxLevelSum(one) << endl; 
		
		return 0;
	}
