/*
ntuition

We notice that the problem could be simply reduced to another one : Remove the (L - n + 1)(L−n+1) th node from the beginning in the list , where LL is the list length. This problem is easy to solve once we found list length LL.

Algorithm

First we will add an auxiliary "dummy" node, which points to the list head. The "dummy" node is used to simplify some corner cases such as a list with only one node, or removing the head of the list. On the first pass, we find the list length LL. Then we set a pointer to the dummy node and start to move it through the list till it comes to the (L - n)(L−n) th node. We relink next pointer of the (L - n)(L−n) th node to the (L - n + 2)(L−n+2) th node and we are done.
*/
 /* Definition for singly-linked list.
 
 */
 
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
		dummy->next = head;
		int length  = 0;
		ListNode *first = head;
		while (first != NULL) {
			length++;
			first = first->next;
		}
		length -= n;
		first = dummy;
		while (length > 0) {
			length--;
			first = first->next;
		}
		first->next = first->next->next;
		return dummy->next;
	}
	ListNode* removeNthFromEnd2(ListNode* head, int n) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *first = dummy;
		ListNode *second = dummy;
		// Advances first pointer so that the gap between first and second is n nodes apart
		for (int i = 1; i <= n + 1; i++) {
			first = first->next;
		}
		// Move first to the end, maintaining the gap
		while (first != NULL) {
			first = first->next;
			second = second->next;
		}
		second->next = second->next->next;
		return dummy->next;
	}
};

int main(void)
{
	Solution sol;
	ListNode *one = new ListNode(1);
	ListNode *two = new ListNode(2);
	ListNode *eight = new ListNode(8); 
	ListNode *three = new ListNode(3);
	ListNode *four = new ListNode(4);
	ListNode *nine = new ListNode(9);
	
	one->next = two;
	two->next = eight; 
	eight->next = three;
	three->next = four;
	four->next = nine; 
	
	ListNode *result = sol.removeNthFromEnd(one, 2); 
	
	ListNode *curr = result; 
	
	while(curr != NULL)
	{
		cout << curr->val << " ";
		curr = curr->next; 
		
	}
	cout << endl;
	
	ListNode *result2 = sol.removeNthFromEnd2(one, 2);
	ListNode *curr2 = result2; 	
	while(curr2 != NULL)
	{
		cout << curr2->val << " ";
		curr2 = curr2->next; 
		
	}
	
	return 0;
}