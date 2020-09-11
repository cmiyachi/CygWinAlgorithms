#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
/*
// Definition for a Node.

*/

/*
public class Solution {
  // HashMap which holds old nodes as keys and new nodes as its values.
  HashMap<Node, Node> visitedHash = new HashMap<Node, Node>();

  public Node copyRandomList(Node head) {

    if (head == null) {
      return null;
    }

    // If we have already processed the current node, then we simply return the cloned version of
    // it.
    if (this.visitedHash.containsKey(head)) {
      return this.visitedHash.get(head);
    }

    // Create a new node with the value same as old node. (i.e. copy the node)
    Node node = new Node(head.val, null, null);

    // Save this value in the hash map. This is needed since there might be
    // loops during traversal due to randomness of random pointers and this would help us avoid
    // them.
    this.visitedHash.put(head, node);

    // Recursively copy the remaining linked list starting once from the next pointer and then from
    // the random pointer.
    // Thus we have two independent recursive calls.
    // Finally we update the next and random pointers for the new node created.
    node.next = this.copyRandomList(head.next);
    node.random = this.copyRandomList(head.random);

    return node;
  }
} **/
class Solution {
public:
	map<Node*,Node*> visitedHash; 
    Node* copyRandomList(Node* head) {
		if (head == NULL) return NULL; 
		
		if (visitedHash.find(head) != visitedHash.end()) return visitedHash[head]; 
		
		Node* node = new Node(head->val, NULL, NULL); 
		visitedHash[head] = node; 
		
		node->next = copyRandomList(head->next);
		node->random = copyRandomList(head->random); 
		
		return node; 
        
    }
};

class Solution2 {
public:
	map<Node*,Node*> visitedHash; 
    Node* getClonedNode(Node* head) {
		// If the node exists then
		if (head != NULL)
		{
			// Check if the node is in the visited dictionary
			if (visitedHash.find(head) != visitedHash.end()) return visitedHash[head]; 
			else {
				// Otherwise create a new node, add to the dictionary and return it
				Node* node = new Node(head->val, NULL, NULL); 
				visitedHash[head] = node; 
				return visitedHash[head];
			  }
			  
			return NULL;
		}
	};

	Node* copyRandomList(Node* head) {

		if (head == NULL) return NULL; 
		Node* oldNode = head;

		// Creating the new head node.
		Node* newNode = new Node(oldNode->val, NULL, NULL); 
		visitedHash[oldNode] = newNode; 

		// Iterate on the linked list until all nodes are cloned.
		while (oldNode != NULL) {
		  // Get the clones of the nodes referenced by random and next pointers.
		  newNode->random = getClonedNode(oldNode->random);
		  newNode->next = getClonedNode(oldNode->next);

		  // Move one step ahead in the linked list.
		  oldNode = oldNode->next;
		  newNode = newNode->next;
		}
    return visitedHash[head];
  }
};

int main(void)
{
	
	Solution sol; 
	
	Solution2 sol2;
	
	return 0;
}