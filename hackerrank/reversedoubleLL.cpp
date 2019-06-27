#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* temp = head;
    DoublyLinkedListNode* node = new DoublyLinkedListNode(data);
    if(head == nullptr || temp->data > data) {
        node->next = temp;
        head = node;
    }
    else {
        while(temp->next && data > temp->next->data) {
            temp = temp->next;
        }
        node->prev = temp;
        node->next = temp->next;
        temp->next = node;
    }
    return head;
}
/* 	{
		DoublyLinkedListNode* DoublyLinkedListNode(ListNode* head) {
        DoublyLinkedListNode *prev = nullptr; 
        DoublyLinkedListNode *curr = head;
        while(curr != nullptr) {
            DoublyLinkedListNode *next_temp = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = next_temp;
        }
        
        return prev; 
        
    } */
	
	DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) 
{
	if(head!=nullptr && head->next!=nullptr)
	{
		DoublyLinkedListNode *tmp, *tmpprev, *tmpnext;
		tmp = head;
		while(tmp!=nullptr)
		{
			tmpprev = tmp->prev;
			tmpnext = tmp->next;
			if(tmpnext == nullptr)
			{
				head = tmp;
			}
			tmp->prev = tmpnext;
			tmp->next = tmpprev;
			tmp = tmpnext;
		}
	}
	return head;
}


int main()
{
    ofstream cout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        DoublyLinkedListNode* llist1 = reverse(llist->head);

        print_doubly_linked_list(llist1, " ");
        cout << "\n";

        free_doubly_linked_list(llist1);
    }

    cout.close();

    return 0;
}
