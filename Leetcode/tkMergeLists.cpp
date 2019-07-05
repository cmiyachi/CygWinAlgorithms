#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
 
class Solution {
public:
    Solution():count(0), while_loop(0) {
    }
    /*
     * divide and conquer is far more fast
     * beats 89.10% of cpp submissions
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = (int)lists.size();
        if(k==0) return NULL;
        if(k==1) return lists[0];
        return doMerge(lists, 0, (int)lists.size()-1);
    }
    ListNode* doMerge(vector<ListNode*>& lists, int left, int right) {
        if(left==right) return lists[left];
        else if(left+1==right) return mergeTwoLists2(lists[left], lists[right]);
        ListNode* l1 = doMerge(lists, left, (left+right)/2);
        ListNode* l2 = doMerge(lists, (left+right)/2+1, right);
        return mergeTwoLists2(l1, l2);
    }

    /*
     * if use this instead.
     * but runtime in leetcode is around 349 ms
     * beats 4.25% cpp submissions.
     */
    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        count++;
        ListNode* head = NULL;
        ListNode** x = &head;
        while(l1 && l2) {
            while_loop++;
            if (l1->val < l2->val) {
                //head = l1;
                *x = l1;
                x = &(*x)->next;
                l1 = l1->next;
            } else {
                *x = l2;
                x = &(*x)->next;
                l2 = l2->next;
            }
        }
        *x = l1 ? l1 : l2;
        return head;
    }


    /*
     * reuse the algorithm in mergeTwoLists it is so sample.
     * but runtime in leetcode is around 500 ms
     * beats 2.23% of cpp submissions.
     */
    ListNode* mergeKListsSlow(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        for (auto i : lists) {
            head = mergeTwoLists2(head, i);
        }
        return head;
    }

    ListNode* mergeTwoListsRecursive(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoListsRecursive(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoListsRecursive(l1, l2->next);
            return l2;
        }
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return mergeTwoListsRecursive(l1, l2);
    }
    int count;
    int while_loop;
};
// function to print the singly linked list 
void printList(struct ListNode* head) 
{ 
	while (head != NULL) { 
		cout << head->val << " "; 
		head = head->next; 
	} 
} 

// Utility function to create a new node 
struct ListNode* newNode(int val) 
{ 
	// allocate node 
	struct ListNode* new_node = new ListNode(-1); 

	// put in the val 
	new_node->val = val; 
	new_node->next = NULL; 

	return new_node; 
} 

// Driver program to test above 
int main() 
{ 
	int k = 3; // Number of linked lists 
	int n = 4; // Number of elements in each list 

	// an array of pointers storing the head nodes 
	// of the linked lists 
	vector<ListNode*> arr(k); 

	// creating k = 3 sorted lists 
	arr[0] = newNode(1); 
	arr[0]->next = newNode(3); 
	arr[0]->next->next = newNode(5); 
	arr[0]->next->next->next = newNode(7); 

	arr[1] = newNode(2); 
	arr[1]->next = newNode(4); 
	arr[1]->next->next = newNode(6); 
	arr[1]->next->next->next = newNode(8); 

	arr[2] = newNode(0); 
	arr[2]->next = newNode(9); 
	arr[2]->next->next = newNode(10); 
	arr[2]->next->next->next = newNode(11); 

	// merge the k sorted lists 
	Solution sol; 
	struct ListNode* head = sol.mergeKLists(arr	); 

	// print the merged list 
	printList(head); 

	return 0; 
} 
