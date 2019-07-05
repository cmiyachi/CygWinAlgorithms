#include <bits/stdc++.h>

using namespace std;

struct ListNode* mergeKSortedLists(vector<ListNode*> arr, int k) ;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

/*
from Queue import PriorityQueue

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        head = point = ListNode(0)
        q = PriorityQueue()
        for l in lists:
            if l:
                q.put((l.val, l))
        while not q.empty():
            val, node = q.get()
            point.next = ListNode(val)
            point = point.next
            node = node.next
            if node:
                q.put((node.val, node))
        return head.next
		
*/		
		/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		struct ListNode* head = mergeKSortedLists(lists, lists.size());
		
		return head; 
        
    }
};


// 'compare' function used to build up the 
// priority queue 
struct compare { 
	bool operator()(struct ListNode* a, struct ListNode* b) 
	{ 
		return a->val > b->val; 
	} 
}; 

// function to merge k sorted linked lists 
struct ListNode* mergeKSortedLists(vector<ListNode*> arr, int k) 
{ 
	struct ListNode* head = NULL, *last; 

	// priority_queue 'pq' implemeted as min heap with the 
	// help of 'compare' function 
	priority_queue<ListNode*, vector<ListNode*>, compare> pq; 

	// push the head nodes of all the k lists in 'pq' 
	for (int i = 0; i < k; i++) 
		pq.push(arr[i]); 

	// loop till 'pq' is not empty 
	while (!pq.empty()) { 

		// get the top element of 'pq' 
		struct ListNode* top = pq.top(); 
		pq.pop(); 

		// check if there is a node next to the 'top' node 
		// in the list of which 'top' node is a member 
		if (top->next != NULL) 
			// push the next node in 'pq' 
			pq.push(top->next); 

		// if final merged list is empty 
		if (head == NULL) { 
			head = top; 

			// points to the last node so far of 
			// the final merged list 
			last = top; 
		} 

		else { 
			// insert 'top' at the end of the merged list so far 
			last->next = top; 

			// update the 'last' pointer 
			last = top; 
		} 
	} 

	// head node of the required merged list 
	return head; 
} 

// function to print the singly linked list 
void printList(struct ListNode* head) 
{ 
	while (head != NULL) { 
		cout << head->val << " "; 
		head = head->next; 
	} 
} 

// Utility function to create a new node 
struct ListNode* newNode(int val) 
{ 
	// allocate node 
	struct ListNode* new_node = new ListNode(-1); 

	// put in the val 
	new_node->val = val; 
	new_node->next = NULL; 

	return new_node; 
} 

// Driver program to test above 
int main() 
{ 
	int k = 3; // Number of linked lists 
	int n = 4; // Number of elements in each list 

	// an array of pointers storing the head nodes 
	// of the linked lists 
	vector<ListNode*> arr(k); 

	// creating k = 3 sorted lists 
	arr[0] = newNode(1); 
	arr[0]->next = newNode(3); 
	arr[0]->next->next = newNode(5); 
	arr[0]->next->next->next = newNode(7); 

	arr[1] = newNode(2); 
	arr[1]->next = newNode(4); 
	arr[1]->next->next = newNode(6); 
	arr[1]->next->next->next = newNode(8); 

	arr[2] = newNode(0); 
	arr[2]->next = newNode(9); 
	arr[2]->next->next = newNode(10); 
	arr[2]->next->next->next = newNode(11); 

	// merge the k sorted lists 
	Solution sol; 
	struct ListNode* head = sol.mergeKLists(arr	); 

	// print the merged list 
	printList(head); 

	return 0; 
} 
