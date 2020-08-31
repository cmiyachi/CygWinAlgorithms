


// CPP program to find count of smaller 
// elements on right side using set in C++ 
// STL. 
#include <bits/stdc++.h> 
using namespace std; 

class Solution3 {
public:
    vector<int> countSmaller(vector<int>& nums) {

	int n = nums.size();
	vector<int> countSmaller(n,0);

	  for (int i = 0; i < n; i++) 
	  { 
		for (int j = i+1; j < n; j++) 
		{ 
		   if (arr[j] < arr[i]) 
			 countSmaller[i]++; 
		} 
	  } 
	  return countSmaller; 
	} 
};

class Solution2 {
public:
    vector<int> countSmaller(vector<int>& nums) {
		set<int> s; 
		int len = nums.size();
		vector<int> result(len); 
		for (int i = len - 1; i >= 0; i--) { 
			s.insert(nums[i]); 
			auto it = s.lower_bound(nums[i]); 
			result[i] = distance(s.begin(), it); 
		} 
		
		return result;

	}
};

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int value){
        val = value;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    map<Node*,int>smalls;
    void insert_into_BST(Node* &root, int val, int &c){
        if(root==NULL){
            Node* new_node = new Node(val);
            root = new_node;
            smalls[root] = 0;
        }
        else if(val<=root->val){
            smalls[root]++;
            insert_into_BST(root->left,val,c);
        }
        else if(val==root->val){
            c += smalls[root];
            insert_into_BST(root->left,val,c);
        }
        else{
            c += smalls[root]+1;
            insert_into_BST(root->right,val,c);
        }
        return;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>counts(n,0);
        Node* root = NULL;
        for(int i=n-1;i>=0;i--){
            int c = 0;
            insert_into_BST(root,nums[i],c);
            counts[i] = c;
        }
        return counts;
    }
};	


// Driver code 
int main(void) 
{ 
	vector<int> A{12, 1, 2, 3, 0, 11, 4}; 
	Solution sol;
	vector<int> result = sol.countSmaller(A);
	for (int i = 0; i < result.size(); i++) 
        cout << result[i] << " "; 
	return 0; 
} 
