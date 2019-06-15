/*
 * C++ Program to Implement Priority Queue
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
 
/*
 * Node Declaration
 */
struct node
{
	int priority;
	int data;
	struct node *nextNode;
};
/*
 * Class Priority Queue
 */
class PriorityQueue
{
    private:
        node *top;
    public:
        PriorityQueue()
        {
            top = NULL;
        }
        /*
         * Insert into Priority Queue
         */
        void insert(int data, int priority)
        {
            node *newNode, *iterateNode;
            newNode = new node;
            newNode->data = data;
            newNode->priority = priority;
			newNode->nextNode = NULL; 
            if (top == NULL || priority < top->priority)
            {
                newNode->nextNode = top;
                top = newNode;
            }
            else
            {
                iterateNode = top;
                while (iterateNode->nextNode != NULL && iterateNode->nextNode->priority <= priority)
                    iterateNode=iterateNode->nextNode;
                newNode->nextNode = iterateNode->nextNode;
                iterateNode->nextNode = iterateNode;
            }
        }
        /*
         * Delete from Priority Queue
         */
        void remove()
        {
            node *thisNode;
            if(top == NULL)
                return; 
            
			thisNode = top;
			top = top->nextNode;
			free(thisNode);
        }
        /*
         * Print Priority Queue
         */
        void display()
        {
            node *ptr;
            ptr = top;
            if (top == NULL)
                cout<<"Queue is empty\n";
            else
            {	cout<<"Queue is :\n";
                cout<<"Priority       Data\n";
                while(ptr != NULL)
                {
                    cout<<ptr->priority<<"                 "<<ptr->data<<endl;
                    ptr = ptr->nextNode;
                }
            }
        }
};
/*
 * Main
 */
int main()
{
    int choice, item, priority;
    PriorityQueue pq; 
    do
    {
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.Display\n";
        cout<<"4.Quit\n";
        cout<<"Enter your choice : "; 
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Input the item value to be added in the queue : ";
            cin>>item;
            cout<<"Enter its priority : ";
            cin>>priority;
            pq.insert(item, priority);
            break;
        case 2:
            pq.remove();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            break;
        default :
            cout<<"Wrong choice\n";
        }
    }
    while(choice != 4);
    return 0;
}