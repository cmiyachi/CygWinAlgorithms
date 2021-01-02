/// https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *A) {
        /*
        unordered_map<ListNode* ,bool> mymap;
        while(A!=NULL){
            if(mymap.count(A)){
                return true;
            }
            mymap[A] = true;
            A=A->next;
        }
        return false;
        */
        
        ListNode *slow = A, *fast=A;
        while(fast && fast->next){
            fast = fast->next->next;  /// to avoid runtime
            slow = slow->next;
            
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};

class Solution2 {
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

// algoexpert

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};

LinkedList *findLoop(LinkedList *head) {
  // Write your code here.
	if (head == NULL) return head; 
	if (head->next == NULL) return head; 
	if (head->next->next == NULL) return NULL;
	
	LinkedList *slow= head->next; 
	LinkedList *fast = head->next->next; 
	
	while (slow != fast)
	{
		slow = slow->next;
		fast =  fast->next->next; 
	}
	
	slow = head; 
	
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next; 
	}
	
  return slow;  
}
