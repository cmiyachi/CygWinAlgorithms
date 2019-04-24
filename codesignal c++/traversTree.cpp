 #include <bits/stdc++.h>
 #include <queue>
 
 using namespace std; 
 
 template<typename T>
	struct Tree {
		Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
		T value;
		Tree *left;
		Tree *right;
	};
	

std::vector<int> traverseTree(Tree<int> * t) {
    
    std::vector<int> bfs;  // breadth first search  
    std::queue<Tree<int> * > tmp; //create a queue for the tree
    
    if(t != nullptr) tmp.push(t);
    
    while(!tmp.empty()){
        Tree<int> * node = tmp.front();
        tmp.pop();
        bfs.push_back(node->value);
        if(node->left != nullptr) tmp.push(node->left);
        if(node->right != nullptr) tmp.push(node->right);
    }
    return bfs;
}

int main(void)
{
	Tree<int> t = Tree<int>(1); 
	Tree<int> t2 = Tree<int>(2);
	Tree<int> t4 = Tree<int>(4);
	Tree<int> t3 = Tree<int>(3);
	Tree<int> t5 = Tree<int>(5);
	t.left = &t2; 
	t.right = &t4;
	t2.left = &t3;
	t4.right = &t5;
	
	vector<int> result = traverseTree(&t); 
	
	for (int i = 0; i < result.size(); i++)
	{
		cout << " " << result[i];
	}
	
		
	
	return 0;
}