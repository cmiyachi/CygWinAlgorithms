#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
		set<ListNode*> nodesseen;
		while (head != NULL)
		{
			if (nodesseen.find(head) != nodesseen.end())
				return true; 
			else 
				nodesseen.insert(head);
			
			head = head->next;
		} // while
        
		return false; 
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) 
			return false;
		
		ListNode* slow = head; 
		ListNode* fast = head->next; 
		while (slow != fast) {
			if (fast == NULL || fast->next == NULL) 
				return false;
				
			slow = slow->next;
			fast = fast->next->next;
		} // while
		return true;
    } // function
};


int main(void)
{
	ListNode* a = new ListNode(3);
	a->next = new ListNode(2);
	a->next->next = new ListNode(0); 
	a->next->next->next = new ListNode(4);
	//a->next->next->next = a->next; 
	
	Solution sol;
	
	cout << sol.hasCycle(a);
	
	return 0;
}