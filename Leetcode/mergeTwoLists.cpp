#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
 
class Solution {
	ListNode *result = new ListNode(-1);
	ListNode *curr = result; 
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		
		// look through list to sort into new list
		while ((l1 != NULL) && (l2 != NULL))
		{
			if (l1->val < l2->val)
			{
				curr->next = l1; 
				l1 = l1->next; 
				
			}
			else
			{
				curr->next = l2; 
				l2 = l2->next; 
			}
			curr = curr->next; 
			
			
		} // while
		
		if (l1 != NULL)
			curr->next = l1;
		if (l2 != NULL)
			curr->next  = l2;
				
		return result->next; 
        
    }
};

int main(void)
{
	
	return 0;
	
}