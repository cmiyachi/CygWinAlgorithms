/**Store tree nodes to a list self.tree in bfs order.
Node tree[i] has left child tree[2 * i + 1] and tree[2 * i + 2]

So when insert the Nth node (0-indexed), we push it into the list.
we can find its parent tree[(N - 1) / 2] directly.

C++: **/

    vector<TreeNode*> tree;
    CBTInserter(TreeNode* root) {
        tree.push_back(root);
        for(int i = 0; i < tree.size();++i) {
            if (tree[i]->left) tree.push_back(tree[i]->left);
            if (tree[i]->right) tree.push_back(tree[i]->right);
        }
    }

    int insert(int v) {
        int N = tree.size();
        TreeNode* node = new TreeNode(v);
        tree.push_back(node);
        if (N % 2)
            tree[(N - 1) / 2]->left = node;
        else
            tree[(N - 1) / 2]->right = node;
        return tree[(N - 1) / 2]->val;
    }

    TreeNode* get_root() {
        return tree[0];
    }
	
	/*
	
	nit with root, push all nodes whose has no left or right child;
Insert new node to first node that has no left or right child.
O(1) Insert and O(nleaf) space for queue only keep nodes has no left or right child
Here is the C++ and Python code:
[C++] **/
class CBTInserter {
private:
    queue<TreeNode*> q;
    TreeNode* head;
public:
    CBTInserter(TreeNode* root) {
        head = root;
        init_queue(root);
    }
    void init_queue(TreeNode* root){
        queue<TreeNode*> tq;
        tq.push(root);
        while(!tq.empty()){
            TreeNode* p = tq.front();
            tq.pop();
            if(p->left == NULL || p->right == NULL){
                q.push(p);
            }
            if(p->left != NULL){
                tq.push(p->left);
            }
            if(p->right != NULL){
                tq.push(p->right);
            }
        }
    }
    int insert(int v) {
        TreeNode* no = new TreeNode(v);
        TreeNode* p = q.front();
        if(p->left == NULL){
            p->left = no;
        }else{
            p->right = no;
            q.pop();
        }
        q.push(no);
        return p->val;
    }
    
    TreeNode* get_root() {
        return head;
    }
};