 #include <bits/stdc++.h>
 #include <stddef.h>
 #include <queue>
 
 using namespace std; 
 

 
 template<typename T>
	struct Tree {
		Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
		T value;
		Tree *left;
		Tree *right;
	};
	
	
// DEPTH FIRST SEARACH EXAMPLE: FIND THE SUMS FROM ROOT TO LEAVES

typedef Tree<int> Node;

void traverse(Node* root, vector<Node*> path, vector<vector<Node*>>& listPath) {
    if (root) path.push_back(root);
    else return;

    if (!root->left && !root->right)
        listPath.push_back(path);
    else {
        if (root->left) traverse(root->left, path, listPath);
        if (root->right) traverse(root->right, path, listPath);


    }
}

long long convertVectorNodeToInt(vector<Node*> nodes) {
    int n = nodes.size();
    long long ret = 0;

    for (int i = 0; i < n; ++i)
        ret += nodes[i]->value * pow(10, n - 1 - i);
    return ret;
}

long long digitTreeSum(Tree<int> * t) {
    vector<Node*> path;
    vector<vector<Node*>> listPath;
    traverse(t, path, listPath);

    long long ret = 0;
    for (int i = 0; i < listPath.size(); ++i)
        ret += convertVectorNodeToInt(listPath[i]);
    return ret;
}

int main(void)
{
	Tree<int> t = Tree<int>(1); 
	Tree<int> t2 = Tree<int>(0);
	Tree<int> t4 = Tree<int>(3);
	Tree<int> t3 = Tree<int>(1);
	Tree<int> t5 = Tree<int>(4);

	t.left = &t2; 
	t.right = &t5;
	t2.right = &t3;
	t2.left = &t4;
	
	long long result = digitTreeSum(&t); 
	
	
	
	
	cout << " " << result;
	
		
	
	return 0;
}