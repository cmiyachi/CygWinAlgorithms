#include <iostream>
#include <string>
#include <set>
struct Node {
	int data;
	struct Node* next;
};

bool has_cycle(Node*);

int main(int argc, char* argv[]){

	// Sample  [A] -> [B] -> [C]
	//                 ^	  |
	//		   |______|

	Node* a = new Node;
	a->data = 100;
	a->next = NULL;

	Node* b = new Node;
	b->data = 50;
	b->next = NULL;

	Node* c = new Node;
	c->data = 1;
	c->next = NULL;

	a->next = b;
	b->next = c;
	c->next = b;

	std::cout << "Cycle: " << has_cycle(a) << std::endl;

	return 0;
}




bool has_cycle(Node* head) {
	bool ret = false;
	std::set<Node *> seen;
	
	while( head != NULL ){
		if( seen.find(head) != seen.end() )
			return true;
		seen.insert(head);
		head = head->next;
	}
	return ret;
}

