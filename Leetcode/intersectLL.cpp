// https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/
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
 
 // if bool is requied - if lists have same end point, true 
 // otherwise false

class Solution2 {
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
class Solution {
public:
    
    
    int length(ListNode* head){
        int count=0;
        while(head!=NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        /*while(A!=NULL){
             ListNode *head2 = B;
            while(head2!=NULL){
                if(A==head2){
                    return A;
                }
                
                head2= head2->next;
            }
            A = A->next;
            
        }
        return NULL;*/
        
        /*unordered_map<ListNode* , bool> mymap;
        while(B!=NULL){
            mymap[B] = true;
            B = B->next;
        }
        
        while(A!=NULL){
            if(mymap.count(A)) return A;  /// intersection
            A = A->next;
        }
        return NULL;
        */
        
        
        int m = length(A);
        int n = length(B);
        
        int d = abs(n-m);
        if(m>n)swap(A,B);
        /// B is bigger
        
        for(int i=0;i<d;i++){
            B = B->next;
        }
        
        /// A and B are equidistant
        while(A!=NULL && B!=NULL){
            if(A==B){
                return A;
            }
            
            A=A->next;
            B=B->next;
        }
        
        return NULL;
    }
};