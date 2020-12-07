#include <bits/stdc++.h>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = NULL;
  }
};

LinkedList *reverseLinkedList(LinkedList *head) {
  // Write your code here.
	LinkedList *curr = head; //p2
	LinkedList *prev = NULL; //p1
	
	while (curr != NULL)
	{
		LinkedList *temp = curr->next; //p3
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	
  return prev; 
}

int main(void)
{
	
	LinkedList *one = new LinkedList(10);
	LinkedList *two = new LinkedList(20);
	LinkedList *three = new LinkedList(30);
	LinkedList *four = new LinkedList(40);
	LinkedList *five = new LinkedList(50);
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	
	LinkedList *revList = reverseLinkedList(one);
	LinkedList *curr = revList; //p2
	
	
	while (curr != NULL)
	{
		cout << curr->value << " "; 
		curr = curr->next; 
	}
	
	
	return 0;
}