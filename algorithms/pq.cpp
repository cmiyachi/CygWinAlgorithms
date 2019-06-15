// C code to implement Priority Queue 
// using Linked List 
#include <bits/stdc++.h>

using namespace std;

// Node 
typedef struct node { 
	int data; 

	// Lower values indicate higher priority 
	int priority; 

	struct node* next; 

} Node; 


/*
 * Class Priority Queue
 */
class PriorityQueue
{
    private:
        Node *head;
    public:
        PriorityQueue()
        {
            head = NULL;
        }
        /*
         * Insert into Priority Queue
         */
        void insert(int data, int priority)
        {
            node *newNode;
			newNode = new Node;
            newNode->data = data;
            newNode->priority = priority;
			newNode->next = NULL; 
			
			Node* start = (head); 

			// Special Case: The head of list has lesser 
			// priority than new node. So insert new 
			// node before head node and change head node. 
			if ((head == NULL) ||head->priority > priority) { 

				// Insert New Node before head 
				newNode->next = head; 
				(head) = newNode; 
			} 
			else { 

				// Traverse the list and find a 
				// position to insert new node 
				while (start->next != NULL && 
					start->next->priority < priority) { 
					start = start->next; 
				} 

				// Either at the ends of the list 
				// or at required position 
				newNode->next = start->next; 
				start->next = newNode; 
			} 

		}

		// Removes the element with the 
		// highest priority form the list 
		void remove() 
		{ 
			Node* temp = head; 
			(head) = (head)->next; 
			free(temp); 
		} 

		// Function to check is list is empty 
		bool isEmpty() 
		{ 
			return (head) == NULL; 
		} 
		
		void display()
        {
            node *ptr;
            ptr = head;
            if (head == NULL)
                cout<<"Queue is empty\n";
            else
            {	cout<<"Queue is :\n";
                cout<<"Priority       Data\n";
                while(ptr != NULL)
                {
                    cout<<ptr->priority<<"                 "<<ptr->data<<endl;
                    ptr = ptr->next;
                }
            }
        }
};

// Driver code 
int main() 
{ 
	// Create a Priority Queue 
	// 7->4->5->6 
	PriorityQueue pq;
	pq.insert(4,1);
	pq.insert(5,2);
	pq.insert(6,2);
	pq.insert(7,0);  

	pq.display(); 

	return 0; 
} 
