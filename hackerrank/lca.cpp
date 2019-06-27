// C++ Program for Lowest Common Ancestor in a Binary Tree 
// A O(n) solution to find LCA of two given values n1 and n2 
#include <iostream> 
#include <vector> 

using namespace std; 

class Node {
	public: 
    int data;
    Node* left;
    Node* right;
	
	Node(int data)
	{
		this->data = data; 
		this->left = nullptr;
		this->right = nullptr;
	}
		
};


// A Binary Tree node 
/*struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 
*/

// Utility function creates a new binary tree node with given data 
/*Node * newNode(int k) 
{ 
	Node *temp = new Node; 
	temp->data = k; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
*/

vector<Node *> pathNodes; 

// Finds the path from root node to given root of the tree, Stores the 
// path in a vector path[], returns true if path exists otherwise false 
bool findPath(Node *root, vector<int> &path, int k) 
{ 
	// base case 
	if (root == NULL) return false; 

	// Store this node in path vector. The node will be removed if 
	// not in path from root to k 
	path.push_back(root->data); 
	pathNodes.push_back(root); 

	// See if the k is same as root's data 
	if (root->data == k) 
		return true; 

	// Check if k is found in left or right sub-tree 
	if ( (root->left && findPath(root->left, path, k)) || 
		(root->right && findPath(root->right, path, k)) ) 
		return true; 

	// If not present in subtree rooted with root, remove root from 
	// path[] and return false 
	path.pop_back(); 
	pathNodes.pop_back(); 
	return false; 
} 

// Returns LCA if node n1, n2 are present in the given binary tree, 
// otherwise return -1 
int findLCA(Node *root, int n1, int n2) 
{ 
	// to store paths to n1 and n2 from the root 
	vector<int> path1, path2; 

	// Find paths from root to n1 and root to n1. If either n1 or n2 
	// is not present, return -1 
	if ( !findPath(root, path1, n1) || !findPath(root, path2, n2)) 
		return -1; 

	/* Compare the paths to get the first different value */
	int i; 
	for (i = 0; i < path1.size() && i < path2.size() ; i++) 
		if (path1[i] != path2[i]) 
			break; 
	return path1[i-1]; 
} 


 Node *lca2(Node *root, int v1,int v2) {
		// Write your code here.
		int index = findLCA(root, v1, v2);
		
		return pathNodes[index-1]; 
		
    }

unsigned int _lca(Node* node, const int v1, const int v2, Node** lcaNode) {
	if ((*lcaNode != NULL) || (node == NULL))
		return 0;

	unsigned int numLeft  = _lca(node->left,  v1, v2, lcaNode);
	unsigned int numRight = _lca(node->right, v1, v2, lcaNode);
	unsigned int numNode  = (node->data == v1 || node->data == v2) ? 1 : 0;
	unsigned int total    = numLeft + numRight + numNode;
	if (total == 2 && *lcaNode == NULL)
		*lcaNode = node;
	return total;
}

	
 Node* lca(Node *root, const int v1, const int v2) {
        Node *lcaNode = NULL;
        unsigned int numValues = _lca(root, v1, v2, &lcaNode);
        if (numValues != 2)
            return NULL;
        return lcaNode;
    }



// Driver program to test above functions 
int main() 
{ 
	// Let us create the Binary Tree shown in above diagram. 
	Node * root = new Node(1); 
	root->left = new Node(2); 
	root->right = new Node(3); 
	root->left->left = new Node(4); 
	root->left->right = new Node(5); 
	root->right->left = new Node(6); 
	root->right->right = new Node(7); 
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5) << endl;
	cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)<< endl; 
	cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)<< endl; 
	cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)<< endl; 
	
	Node *temp = lca(root, 4, 5);
	cout << temp->data << endl;
	temp = lca(root, 4, 6);
	cout << temp->data << endl;
	temp = lca(root, 3, 4);
	cout << temp->data << endl;
	temp = lca(root, 2, 4);	
	cout << temp->data << endl;

	return 0; 
} 
