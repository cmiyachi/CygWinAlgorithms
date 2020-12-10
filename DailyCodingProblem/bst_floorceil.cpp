#include <bits/stdc++.h>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = NULL;
    right = NULL;
  }
	 

  BST &remove(int val, BST *parentNode = NULL) {
    // Write your code here.
    // Do not edit the return statement of this method.
	//	#Average 0(log(n)  Space (O)(1))
		BST* currNode = this;
		while (currNode != NULL)
		{
			if (val < currNode->value)
			{
				parentNode = currNode;
				currNode = currNode->left;  
			}
			else if (val > currNode->value)
			{
				parentNode = currNode;
				currNode = currNode->right;
			}
			else
			{
				// both leaves present
				if (currNode->left != NULL && currNode->right != NULL)
				{
					currNode->value = currNode->right->getMinValue();
					currNode->right->remove(currNode->value, currNode); 
				}
				else if (parentNode == NULL) // root of tree
				{
					if (currNode->left != NULL)
					{
						currNode->value = currNode->left->value; 
						currNode->right = currNode->left->right; 
						currNode->left = currNode->left->left;; 
					}
					if (currNode->right != NULL)
					{
						currNode->value = currNode->right->value; 
						currNode->left= currNode->right->left;  
						currNode->right= currNode->right->right; 
					}
					else
					{
						// single node tree - do nothing
					}
					//  node only has left or right
				}	else if (parentNode->left == currNode) // left side of tree
					parentNode->left = currNode->left != NULL ? currNode->left : currNode->right;
				else if (parentNode->right == currNode)
					parentNode->right = currNode->left != NULL ? currNode->left : currNode->right; 
				break; 
			}
		}
    return *this;
  }

  bool contains(int val) {
    // Write your code here.
		BST* currNode = this;
		while (currNode != NULL)
			if (val < currNode->value)
				currNode = currNode->left;
			else if (val > currNode->value)
				currNode = currNode->right;
			else
				return true;
    return false;
  }

  BST &insert(int val) {
		BST *currNode = this;
		while (true)
		{
			if (val < currNode->value)
			{
				if (currNode->left == NULL)
				{
					BST *newNode = new BST(val);
					currNode->left = newNode;
					break;
				}
				else currNode = currNode->left; 
			}
			else
			{
				if (currNode->right == NULL)
				{
					BST *newNode = new BST(val);
					currNode->right = newNode; 
					break;
				}
				else currNode = currNode->right; 
			}
		}
		return *this; 
	}
  
	int getMinValue()
	{
		if (left == NULL)
			return value;
		else
			return left->getMinValue();
	}
}; 
/* Imagine we are moving down the tree, and assume we are root node. 
The comparison yields three possibilities,

A) Root value is equal to key. We are done, root value is ceil value.

B) Root value < key value, certainly the ceil value can't be in left subtree. 
   Proceed to search on right subtree as reduced problem instance.

C) Root value > key value, the ceil value may be in left subtree. 
   We may find a node with is larger value than key value in left subtree, 
   if not the root itself will be ceil node.
*/
// Function to find ceil of a given input in BST. If input is more  
// than the max key in BST, return -1  
int Ceil(BST* root, int input)  
{  
    // Base case  
    if (root == NULL)  
        return -1;  
  
    // We found equal key  
    if (root->value == input)  
        return root->value;  
  
    // If root's key is smaller, ceil must be in right subtree  
    if (root->value < input)  
        return Ceil(root->right, input);  
  
    // Else, either left subtree or root has the ceil value  
    int ceil = Ceil(root->left, input);  
    return (ceil >= input) ? ceil : root->value;  
}  

void get_bounds(BST* root, int input, int &floor, int &ceil)  
{  
    // Base case  
    if (root == NULL)  
        return;  
  
    // We found equal key  
    if (root->value == input)  
	{	
		floor = root->value;
		ceil = root->value;
		return; 
	}	
  
    // If root's key is smaller, ceil must be in right subtree  
    else if (input > root->value )  
	{
		floor = root->value;
        return get_bounds(root->right, input, floor, ceil);  
	}
  
    // Else, either left subtree or root has the ceil value  
    else if ( input <  root->value) 
	{
		ceil = root->value; 
		return get_bounds(root->left, input, floor, ceil);  
	}
		
    return;  
}  
  


// Helper function to find floor and ceil of a given key in BST  
void floorCeilBSTHelper(BST* root, int key, int& floor, int& ceil)  
{  
  
    while (root) {  
  
        if (root->value == key) {  
            ceil = root->value;  
            floor = root->value;  
            return;  
        }  
  
        if (key > root->value) {  
            floor = root->value;  
            root = root->right;  
        }  
        else {  
            ceil = root->value;  
            root = root->left;  
        }  
    }  
    return;  
}  
  
// Display the floor and ceil of a given key in BST.  
// If key is less than the min key in BST, floor will be -1;  
// If key is more than the max key in BST, ceil will be -1;  
void floorCeilBST(BST* root, int key)  
{  
  
    // Variables 'floor' and 'ceil' are passed by reference  
    int floor = -1, ceil = -1;  
  
    floorCeilBSTHelper(root, key, floor, ceil);  
  
    cout << key << ' ' << floor << ' ' << ceil << endl;
}


// Driver program to test above function  
int main()  
{  
    BST* root = new BST(8);  
  
    root->left = new BST(4);  
    root->right = new BST(12);  
  
    root->left->left = new BST(2);  
    root->left->right = new BST(6);  
  
    root->right->left = new BST(10);  
    root->right->right = new BST(14);  
	
	for (int i = 0; i < 16; i++)  
		floorCeilBST(root,i);
  
  for (int i = 0; i < 16; i++)  
	{
			//cout << i << " " << Ceil(root, i) << endl;  
		int floor = -1; int ceil = -1;
		get_bounds(root, i, floor, ceil);
		cout << "input : " << i << " floor " << floor << " ceil " << ceil << endl;
	} 
  
    return 0;  
}  
  /*
  If tree is empty, i.e. root is null, 
   return back to calling function.
2. If current node address is not null, perform the following steps : 
     (a) If current node value matches with the key value - 
             We have found both our floor and ceil value. 
             Hence, we return back to calling function.
    (b) If value in current node is lesser than the key value - 
            We assign the current node value to the variable keeping
            track of current floor value and explore the right subtree,
            as it may contain nodes with values greater than key value.
    (c) If value in current node is greater than the key value - 
            We assign the current node value to the variable keeping track
            of current ceil value and explore the left subtree, as it may
            contain nodes with values lesser than key value.
3. Once we reach null, we return back to the calling function,
   as we have got our required floor and ceil values for the particular key value.*/