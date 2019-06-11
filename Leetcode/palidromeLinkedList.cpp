// https://github.com/FeifeiWang7/LeetCode/blob/19614189a2bd7847cc19f0c9e3e40ab4e036a836/PalindromeLinkedList/cpp.cpp

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

bool isPalindrome(ListNode* head) {

    if (head == NULL || head->next == NULL) return true;

    int n = 0;
    for (ListNode* node = head; node; node = node->next)
        ++n;

    ListNode* node = head;
    ListNode* prev = head;
    for (int i = 0; i < (n + 1) / 2; ++i) {
        prev = node;
        node = node->next;
    }

    ListNode* tail = NULL;
    while (node) {
        auto temp = node->next;
        node->next = tail;
        tail = node;
        node = temp;
    }

    prev->next = tail;

    while (tail && tail->val == head->val) {
        tail = tail->next;
        head = head->next;
    }

    return tail == NULL;
}

int main() {
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(2);
	
	ListNode l4(1);
    ListNode l5(2);
    ListNode l6(1);
    cout << isPalindrome(&l1) << endl;
    l1.next = &l2;
    cout << isPalindrome(&l1) << endl;
    l2.next = &l3;
    cout << isPalindrome(&l1) << endl;
    l3.next = &l4;
    cout << isPalindrome(&l1) << endl;
    l4.next = &l5;
    cout << isPalindrome(&l1) << endl;
    l5.next = &l6;
    cout << isPalindrome(&l1) << endl;
    return 0;
}