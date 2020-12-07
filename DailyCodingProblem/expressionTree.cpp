#include <bits/stdc++.h>
using namespace std;

struct Node {
     char val;
     Node *left;
      Node *right;
      Node() : val(' '), left(nullptr), right(nullptr) {}
      Node(char x) : val(x), left(nullptr), right(nullptr) {}
      Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
};
 

    int eval(Node* root1)
    {
        if(!root1) return 0;
		if (root1->val == '+')
			return eval(root1->left) + eval(root1->right); 
		else if (root1->val == '-')
			return eval(root1->left) - eval(root1->right);
        else if (root1->val == '*')
			return eval(root1->left) * eval(root1->right);
		else if (root1->val == '/')
			return eval(root1->left) / eval(root1->right);
        else
			return root1->val-'0'; 
    }
    
 /*   
    bool checkEquivalence(Node* root1, Node* root2) {
        d = 1;
        eval(root1);
        d = -1;
        eval(root2);
        for(int i : s) if(i) return false;
        return true;
    }
};*/

int main(void)
{
	Node *plus = new Node('*');
	Node *rplus = new Node('+');
	Node *lplus = new Node('+'); 
	Node *three = new Node ('3');
	Node *four = new Node('4');
	Node *two = new Node('2');
	Node *five = new Node('5'); 
	
	 plus->right = rplus;
	 plus->left = lplus;
	
	 rplus->right = three;
	 rplus->left = two;
	
	 lplus->right = four;
	 lplus->left = five; 
	
	cout << eval(plus); 
	
	return 0;
}
	