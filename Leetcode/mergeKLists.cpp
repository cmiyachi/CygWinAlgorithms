// C++ program to merge k sorted arrays of size n each 
#include <bits/stdc++.h> 
using namespace std; 


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
// A Linked List node 
/* struct Node 
{ 
	int val; 
	Node* next; 
};  */

/* Function to print nodes in a given linked list */
void printList(ListNode* node) 
{ 
	while (node != NULL) 
	{ 
		printf("%d ", node->val); 
		node = node->next; 
	} 
} 

/* Takes two lists sorted in increasing order, and merge 
their nodes together to make one big sorted list. Below 
function takes O(Log n) extra space for recursive calls, 
but it can be easily modified to work with same time and 
O(1) extra space */
ListNode* SortedMerge(ListNode* a, ListNode* b) 
{ 
	ListNode* result = NULL; 

	/* Base cases */
	if (a == NULL) 
		return (b); 
	else if(b == NULL) 
		return (a); 

	/* Pick either a or b, and recur */
	if(a->val <= b->val) 
	{ 
		result = a; 
		result->next = SortedMerge(a->next, b); 
	} 
	else
	{ 
		result = b; 
		result->next = SortedMerge(a, b->next); 
	} 

	return result; 
} 

// The main function that takes an array of lists 
// arr[0..last] and generates the sorted output 
ListNode* mergeKListsUtil(vector<ListNode*> arr, int last) 
{ 
	// repeat until only one list is left 
	while (last != 0) 
	{ 
		int i = 0, j = last; 

		// (i, j) forms a pair 
		while (i < j) 
		{ 
			// merge List i with List j and store 
			// merged list in List i 
			arr[i] = SortedMerge(arr[i], arr[j]); 

			// consider next pair 
			i++, j--; 

			// If all pairs are merged, update last 
			if (i >= j) 
				last = j; 
		} 
	} 

	return arr[0]; 
} 

// Utility function to create a new node. 
/* Node *newNode(int val) 
{ 
	struct Node *temp = new Node; 
	temp->val = val; 
	temp->next = NULL; 
	return temp; 
} */ 


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
		
		ListNode* result = mergeKListsUtil(lists, lists.size()-1); 
		
		return result; 
        
    }
};
// Driver program to test above functions 
int main() 
{ 
	int k = 3; // Number of linked lists 
	int n = 4; // Number of elements in each list 

	// an array of pointers storing the head nodes 
	// of the linked lists 
	vector<ListNode*> arr(3); 

	arr[0] = new ListNode(1); 
	arr[0]->next = new ListNode(3); 
	arr[0]->next->next = new ListNode(5); 
	arr[0]->next->next->next = new ListNode(7); 

	arr[1] = new ListNode(2); 
	arr[1]->next = new ListNode(4); 
	arr[1]->next->next = new ListNode(6); 
	arr[1]->next->next->next = new ListNode(8); 

	arr[2] = new ListNode(0); 
	arr[2]->next = new ListNode(9); 
	arr[2]->next->next = new ListNode(10); 
	arr[2]->next->next->next = new ListNode(11); 

	// Merge all lists 
	Solution sol; 
	ListNode* head = sol.mergeKLists(arr); 

	printList(head); 

	return 0; 
} 
