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
	
	typedef Tree<int> Node;
	
vector<int> largestValuesInTreeRows(Tree<int> * t) {
    vector<int> ret;

    if (t) {
        queue<Node*> q;
        q.push(t);
        while (!q.empty()){
            int n = q.size();
            int largest = INT_MIN;
            for (int i = 0; i < n; i++){
                t = q.front();
                q.pop();
                largest = max(largest, t->value);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            ret.push_back(largest);
        }
    }

    return ret;
}

int main(void)
{
	Tree<int> t = Tree<int>(-1); 
	Tree<int> t2 = Tree<int>(5);
	Tree<int> t4 = Tree<int>(7);
	Tree<int> t3 = Tree<int>(1);

	t.left = &t2; 
	t.right = &t4;
	t4.right = &t3;
	
	vector<int> result = largestValuesInTreeRows(&t); 
	
	for (int i = 0; i < result.size(); i++)
	{
		cout << " " << result[i];
	}
	
		
	
	return 0;
}