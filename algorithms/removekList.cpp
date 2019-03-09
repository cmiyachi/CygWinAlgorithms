#include <iostream>
using namespace std; 

// --- Directions
// Implement classes Node and Linked Lists
// See 'directions' document
#include <iostream>
#include <cstdlib>

template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};


class LinkedList {
	public:
		ListNode<int> *head;
		ListNode<int> *prev; 
		int length; 
		LinkedList ();
		~LinkedList (); 
		void insertFirst(int data);
		print();
};

 LinkedList::LinkedList() {
    this->head = NULL;
	this->prev = NULL; 
	this->length = 0; 
  }
 LinkedList::~LinkedList() {
 }
 
 void LinkedList::insertFirst(int data) {
    this->head = new ListNode<int>(data) ; //, this->head);
	this->length++;
  }
  LinkedList::print() {
	ListNode<int> *walk = this->head;
	int i = 0;
	while(walk){
		std::cout << i << ": " << walk->data << std::endl;
		walk = walk->next;
		i++;
	}
  }
 int main()
{
    LinkedList* list = new LinkedList();
    for (int i = 0; i < 100; ++i)
    {
        list->insertFirst(rand() % 100);
    }
    list->print();
    std::cout << "List Length: " << list->length << std::endl;
    delete list;
    return 0;
}
/*  ListNode<int> * removeKFromList(ListNode<int> * l, int k) {
	 if (l->head == NULL)
		 return NULL;
	 
	 // loop through and find values of k
	 ListNode<int> node = new ListNode<int>; 
	 
	 while (node) {
      if (counter === index) {
        return node;
      }

      counter++;
      node = node.next;
    }

}
  
 removeAt(index) {
    if (!this.head) {
      return;
    }

    if (index === 0) {
      this.head = this.head.next;
      return;
    }

    const previous = this.getAt(index - 1);
    if (!previous || !previous.next) {
      return;
    }
    previous.next = previous.next.next;
  } */