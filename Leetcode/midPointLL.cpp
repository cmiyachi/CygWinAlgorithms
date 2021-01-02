/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // naive - traverse 2 x - find length and then iterate len/2
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
         ListNode* slow = head;
         ListNode* fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=NULL){  /// even
            return slow->next;
        }
        return slow;  /// odd
    }
};