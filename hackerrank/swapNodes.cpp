#include <bits/stdc++.h>
using namespace std;

const int NIL = -1;

class Node{
public:
	int data;
	Node *left, *right;
	Node(){
		data = NIL;
		left = right = NULL;
	}
	Node(const int& data){
		this->data = data;
		left = right = NULL;
	}
};

class BST{

	Node *root;


	void constructBST(const int& idx, Node *p, const vector< vector<int> >& indexes){

		int left = indexes[idx][0];
		int right = indexes[idx][1];
		if(left != NIL){
			p->left = new Node(left-1);
			constructBST(left-1, p->left, indexes);
		}
		if(right != NIL){
			p->right = new Node(right-1);
			constructBST(right-1, p->right, indexes);
		}
	}


	void pre_order_util(Node *p, vector<int>& res){
		if(p->left) pre_order_util(p->left, res);
		res.push_back(p->data+1);
		if(p->right) pre_order_util(p->right, res);
	}

	void swap(const int& curr_depth, const int& k, Node *p){
		if(curr_depth%k == 0){
			Node *tmp = p->left;
			p->left = p->right;
			p->right = tmp;
		}
		if(p->left) swap(curr_depth+1, k, p->left);
		if(p->right) swap(curr_depth+1, k, p->right);
	}

public:

	BST(){ root = NULL; }
	BST(const vector< vector<int> >& indexes){
		if(indexes.empty()) return;
		root = new Node(0);
		constructBST(0, root, indexes);
	}

	vector<int> pre_order(){
		if(!root) return vector<int>();
		vector<int> res;
		pre_order_util(root, res);
		return res;
	}

	void swap(const int& k){
		if(!root) return;
		swap(1, k, root);
	}
};

/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    /*
    * Write your code here.
    */
	BST tree(indexes);
	vector< vector<int> > res;
	for(auto query : queries){
		tree.swap(query);
		res.push_back(tree.pre_order());
	}
	return res;
}

int main(){

	int n, q;
	cin >> n;
	vector< vector<int> > indexes(n);
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		indexes[i].push_back(a);
		indexes[i].push_back(b);
	}

	cin >> q;
	vector<int> queries(q);
	for(int i = 0; i < q; i++){
		cin >> queries[i];
	}

	vector< vector<int> > res;
	res = swapNodes(indexes, queries);
	for(auto t : res){
		for(auto el : t){
			cout << el << " ";
		}
		cout << endl;
	}

	return 0;
}