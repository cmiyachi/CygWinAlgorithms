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

int lengthLinkedList(LinkedList *head)
{	
	if (head == NULL)
		return 0;
	 
	 return 1+ lengthLinkedList(head->next);
}

LinkedList *intersectionLinkedList(LinkedList *a, LinkedList *b)
{
	int m = lengthLinkedList(a);
	int n = lengthLinkedList(b);
	
	LinkedList *curr_a = a;
	LinkedList *curr_b = b;
	
	if (m > n)
		for (int i = 0; i < m-n; i++)
			curr_a = curr_a->next;
	else
		for (int i = 0; i < n-m; i++)
			curr_b = curr_b->next;
			
	while (curr_a != curr_b)
	{
		curr_a = curr_a->next;
		curr_b = curr_b->next;
	}
	
	return curr_a;
	
}
int main(void)
{
	
	LinkedList *one = new LinkedList(10);
	LinkedList *two = new LinkedList(20);
	LinkedList *three = new LinkedList(30);
	LinkedList *four = new LinkedList(40);
	LinkedList *five = new LinkedList(50);
	LinkedList *six = new LinkedList(60);
	LinkedList *seven = new LinkedList(70);
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	six->next = seven;
	seven->next = four; 
	
	// LinkedList *revList = reverseLinkedList(one);
	LinkedList *intersect  = intersectionLinkedList(one, six);
	
	cout << intersect->value << endl; 
	
	
	return 0;
}