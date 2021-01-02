/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // traverse to get length
 // n-k+1 = i  - i-1 jumps 
 // but this is two traversals
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode* one = head;
        ListNode* two = head;
        
        while(k--){ /// k times
            two = two->next;
        }
        if(two==NULL){   /// length of ll = k  => delete head node
            return one->next;
        }
        while(two->next!=NULL){
            one = one->next;
            two = two->next;
        }
        
        /// delete kth node from end
        one->next = one->next->next;      /// memory leak
        
        return head;
    }
};

// algoexpert

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};
// better version with two ptrs
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
  // Write your code here.
//	LinkedList new_head(-1); 
//	new_head.next = head; 
	LinkedList *slow = head; 
	LinkedList *fast = head;
	
	//for (int i = 0; i < k; i++)
	int counter = 1;
	while (counter <= k)
	{
		fast = fast->next; 
		counter++;
	}
	
	if (fast == NULL)
	{
		head->value = head->next->value;
		head->next = head->next->next; 
		return; 
	}
	while (fast->next != NULL) 
	{
    fast = fast->next;
		slow = slow->next; 
	}
	
// 	LinkedList  *nodeToBeDeleted = slow->next; 
	slow->next = slow->next->next; 
	
// 	delete nodeToBeDeleted; 
	
// 	head = new_head.next; 
       
}
/*
//this is the 2 iteration version

void removeKthNodeFromEnd(LinkedList *head, int n) {
//  ListNode* removeNthFromEnd(ListNode* head, int n) {
  	LinkedList *dummy = new LinkedList(0);
		dummy->next = head;
		int length  = 0;
		LinkedList *first = head;
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
		return; //dummy->next;
	}
