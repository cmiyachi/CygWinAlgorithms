#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * 
 */
 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
  
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *dummyHead = new ListNode(0); 
		ListNode *p = l1, *q = l2, *curr = dummyHead; 
		int carry = 0; 
		
		while(p != NULL || q != NULL)
		{
			int x = (p != NULL)? p->val : 0; 
			int y = (q != NULL) ? q->val : 0; 
			int sum = carry + x + y;
			carry = sum/10; 
			curr->next = new ListNode(sum % 10); 
			curr = curr->next; 
			if (p != NULL) p = p->next; 
			if (q != NULL) q = q->next; 
		}
		if (carry > 0 )
		{
			curr->next = new ListNode(carry); 
		}
		return dummyHead->next; 
    }
};

int main(void)
{
	Solution sol;
	ListNode *one = new ListNode(1);
	ListNode *two = new ListNode(2);
	ListNode *eight = new ListNode(8); 
	
	one->next = two;
	two->next = eight; 
	
	ListNode *three = new ListNode(3);
	ListNode *four = new ListNode(4);
	ListNode *nine = new ListNode(9);
	
	three->next = four;
	four->next = nine; 
	
	ListNode *result = sol.addTwoNumbers(three, one); 
	
	ListNode *curr = result; 
	
	while(curr != NULL)
	{
		cout << curr->val << " ";
		curr = curr->next; 
		
	}
	return 0;
}

/*public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummyHead = new ListNode(0);
    ListNode p = l1, q = l2, curr = dummyHead;
    int carry = 0;
    while (p != null || q != null) {
        int x = (p != null) ? p.val : 0;
        int y = (q != null) ? q.val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (p != null) p = p.next;
        if (q != null) q = q.next;
    }
    if (carry > 0) {
        curr.next = new ListNode(carry);
    }
    return dummyHead.next;
}*/ 