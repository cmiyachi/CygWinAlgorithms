/// https://leetcode.com/problems/reverse-linked-list/submissions/


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
    ListNode* reverseList(ListNode* head) {
         ListNode *curr = head;
         ListNode *prev = NULL;
        
        while(curr!=NULL){
            ListNode *n = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr= n;
        }
        
        return prev;
    }
};
class Solution2 {
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

// from algoexpert
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = NULL;
  }
};

LinkedList *reverseLinkedList(LinkedList *head) {
  // Write your code here.
	LinkedList *curr = head; //p2
	LinkedList *prev = NULL; //p1
	
	while (curr != NULL)
	{
		LinkedList *temp = curr->next; //p3
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	
  return prev; 
}
