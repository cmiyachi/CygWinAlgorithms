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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		set<ListNode*> Apointers;
		
		ListNode *curr = headA;
		set<ListNode*>::iterator it;
		
		while (curr != NULL)
		{
			Apointers.insert(curr);
			curr = curr->next; 
		}
		
		curr = headB; 
		while (curr != NULL)
		{
			set<ListNode*>::iterator it;
			it = Apointers.find(curr);
			if (*it != NULL)
				return *it; 
		}
		
		return NULL; 
    }
};

class Solution {
	public:
		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			size_t lengthA = getLength(headA);
			if (lengthA == 0) {
				return NULL;
			}
			size_t lengthB = getLength(headB);
			if (lengthB == 0) {
				return NULL;
			}

			size_t diff;
			if (lengthA < lengthB) {
				diff = lengthB - lengthA;
				while (diff > 0) {
					headB = headB->next;
					diff--;
				}
			}
			else if (lengthA > lengthB) {
				diff = lengthA - lengthB;
				while (diff > 0) {
					headA = headA->next;
					diff--;
				}
			}

			while (headA != NULL && headB != NULL) {
				if (headA == headB) {
					return headA; 
				}
				headA = headA->next;
				headB = headB->next;
			}

			return NULL;
		}
	
	private:
		size_t getLength(ListNode *head) {
			if (head == NULL) {
				return 0;
			}
			size_t size = 1;
			while (head->next != NULL) {
				head = head->next;
				size++;
			}

			return size;
		}
};

int main () {
   
    ListNode* a = new ListNode(1); 
	a->next = new ListNode(2); 
	a->next->next = new ListNode(3); 
	a->next->next->next = new ListNode(4);
	a->next->next->next->next = new ListNode(5);
	ListNode* b = new ListNode(6);
	b->next = new ListNode(7); 
	b->next->next = a->next; 
	
	
	Solution sol;
	
	ListNode* result = sol.getIntersectionNode(a,b);
	
	if (result != NULL) 
		cout <<  result->val ;
	else cout << "null returned"; 

   
    return 0;
}