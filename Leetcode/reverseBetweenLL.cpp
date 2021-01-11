/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int curPos =1;
        ListNode *start = head;
        ListNode *currNode = head;
        
        while (curPos < m)
        {
            start = currNode;
            currNode = currNode->next; 
            curPos++;
        }
        
        ListNode * newList;
        ListNode* tail = currNode; 
        
        while (curPos >= m && curPos <= n)
        {
            auto next = currNode->next;
            currNode->next = newList; 
            newList = currNode; 
            currNode = next;
            curPos++;
        }
        
        start->next = newList; 
        tail->next = currNode;
        
        if (m > 1) return head; 
        else return newList; 
        
    }
};
