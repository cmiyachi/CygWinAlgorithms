/// https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *A) {
        /*unordered_map<ListNode* ,bool> mymap;
        while(A!=NULL){
            if(mymap.count(A)){
                return A;
            }
            mymap[A] = true;
            A=A->next;
        }
        return NULL;*/
        
        
        
        ListNode *slow = A, *fast=A;
        while(fast && fast->next){
            fast = fast->next->next;  /// to avoid runtime
            slow = slow->next;
            
            if(slow==fast){
                break;   /// cycle detected
            }
        }
        
        if(fast==NULL || fast->next==NULL) return NULL;
        
        slow = A;
        while(slow!=fast){
            slow=slow->next;
            fast = fast->next;
        }
        return slow;
        

        /*
        /// size of loop
        slow = slow->next;
        int k=1;
        while(slow!=fast){
            slow = slow->next;
            k++;
        }
        
        ListNode *one = A;
        ListNode *two = A;
        
        /// move 2nd ptr k steps ahead
        while(k--) two = two->next;
        
        
        /// move both ptr at same speed
        
        while(one!=two){
            one = one->next;
            two=two->next;
        }
        return one;*/
        
        
    }
};