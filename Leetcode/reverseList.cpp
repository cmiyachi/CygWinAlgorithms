#include <bits/stdc++.h>
using namespace std; 

/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr; 
        ListNode *curr = head;
        while(curr != nullptr) {
            ListNode *next_temp = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = next_temp;
        }
        
        return prev; 
        
    }
};

void printLL(ListNode *head)
{
	ListNode *curr = head; 
	
	while (curr != NULL)
	{
		cout << curr->val << " "; 
		curr = curr->next; 
	}
	cout << endl; 
}

/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	ListNode *ll = new ListNode(10); 
	ll->next = new ListNode(20);  
	ll->next->next = new ListNode(30);
	ll->next->next->next = new ListNode(40);  
	ll->next->next->next->next = new ListNode(50);  

	cout << "Given linked list\n"; 
	printLL(ll); 

	Solution sol;
	
	ListNode *revLL = sol.reverseList(ll); 

	cout << "\nReversed Linked list \n"; 
	printLL(revLL); 
	
	return 0; 
} 
