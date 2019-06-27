#include<bits/stdc++.h> 
#include<iostream> 
using namespace std; 

/* A binary tree node has data, 
pointer to left child and 
a pointer to right child */
// class node 
// { 
	// public: 
	// int data; 
	// node* left; 
	// node* right; 
	
	// /* Constructor that allocates 
	// a new node with the given data 
	// and NULL left and right pointers. */
	// node(int data) 
	// { 
		// this->data = data; 
		// this->left = NULL; 
		// this->right = NULL; 
	// } 
// }; 

struct Node {
		int data;
		Node* left;
		Node* right;
	};
	
Node * newNode(int k) 
{ 
	Node *temp = new Node; 
	temp->data = k; 
	temp->left = temp->right = NULL; 
	return temp; 
}

int isBSTUtil(Node* node, int min, int max); 

/* Returns true if the given 
tree is a binary search tree 
(efficient version). */
int isBST(Node* node) 
{ 
	return(isBSTUtil(node, INT_MIN, INT_MAX)); 
} 

/* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
int isBSTUtil(Node* node, int min, int max) 
{ 
	/* an empty tree is BST */
	if (node==NULL) 
		return 1; 
			
	/* false if this node violates 
	the min/max constraint */
	if (node->data < min || node->data > max) 
		return 0; 
	
	/* otherwise check the subtrees recursively, 
	tightening the min or max constraint */
	return
		isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values 
		isBSTUtil(node->right, node->data+1, max); // Allow only distinct values 
} 

	void funct(Node* root,vector<int> &v){
    if(root==NULL) return;
    funct(root->left,v);
    v.push_back(root->data);
    funct(root->right,v);
    
    return;
}

   bool checkBST(Node* root) {
        vector<int> v;
        funct(root,v);
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1]) return 0;
        }
        return 1;
   }

/* Driver code*/
int main() 
{ 
	Node *root = newNode(4); 
	root->left = newNode(2); 
	root->right = newNode(5); 
	root->left->left = newNode(1); 
	root->left->right = newNode(3); 
	
	if(checkBST(root)) 
		cout<<"Is BST"; 
	else
		cout<<"Not a BST"; 
		
	return 0; 
} 

