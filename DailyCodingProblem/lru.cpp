#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	string key;
	int value;
	Node *prev;
	Node *next;
	
	Node(int value, string key)
	{
		this->value = value;
		this->key = key;
		 this->next = NULL;
		this->prev = NULL;
	}
};

class LinkedList {
public:

  Node *head;
  Node *tail; 

  LinkedList() {
   head = new Node(0,"head");
   tail = new Node(0,"tail");
   head->next = tail;
   tail->prev = head; 
  }
  
  Node *get_head()
  {
	  return head->next;
  }
  
  Node *get_tail()
  {
	  return tail->prev;
  }
  
  void add(Node *node)
  {
	  Node *prev = tail->prev;
	  prev->next = node; 
	  node->prev = prev;
	  node->next = tail; 
	  tail->prev = node; 
  }
  
  void remove(Node *node)
  {
	  Node *prev = node->prev;
	  Node *next = node->next;
	  prev->next = next; 
	  next->prev = prev; 
  }
};
  
class LRUCache
{
	public:
	int max_size;
	LinkedList *cache;
	unordered_map<string,Node *> dict; 
	
	LRUCache(int n)
	{
		max_size = n;
		cache = new LinkedList();
	}
	
	void set(string key, int value)
	{
		if (dict.find(key) != dict.end())
			dict.erase(key); 
		
		Node *n = new Node(value, key);
		cache->add(n); 
		dict[key] = n; 
		
		if (dict.size() > max_size)
		{
			Node *head = cache->get_head();
			cache->remove(head);
			dict.erase(head->key);
		}
	}
	
	Node* get(string key)
	{
		if (dict.find(key) != dict.end())
		{
			Node *node = dict[key]; 
			
			cache->remove(node);
			cache->add(node); 
			
			return node;
		}
		
		return NULL;
	}
	
	void printCache()
	{
		Node *curr = cache->head;
		cout << "**********************" << endl;
		while (curr != NULL)
		{
			cout << curr->value << " " << curr->key << endl;
			curr = curr->next; 
		}
	}
};

int main(void)
{
	LRUCache *lru_cache = new LRUCache(3);
	
	lru_cache->set("10",10);
	lru_cache->set("20",20);
	lru_cache->set("30",30);
	lru_cache->set("40",40);
	lru_cache->set("50",50);
	Node *node = lru_cache->get("30");
	cout << node->value << endl; 
	lru_cache->printCache(); 
	
	return 0;
}

class LFUCache {
public:
    struct DoubleList {
        int key;
        int val;
        int freq;
        struct DoubleList * prev;
        struct DoubleList * next;
        DoubleList(int k, int v, int f, struct DoubleList *p, struct DoubleList * n) {
            key = k;
            val = v;
            freq = f;
            prev = p;
            next = n;
        };
    };
    class MyList{
        struct DoubleList * head;
        struct DoubleList * tail;
        int size;

    public:
        MyList() {
            size = 0;
            head = tail = NULL;
        }
        
        bool empty(){
            return size == 0;
        }
        void remove(struct DoubleList * node){
            if (size == 1 || head == node) {
                pop_front();
                return;
            }
            else {
                if (node == tail)
                    tail = node->prev;
                node->prev->next = node->next;
                if (node->next)
                    node->next->prev = node->prev;
            }            
            size --;
        }
        void push_back(struct DoubleList * node) {
            if (size == 0) {
                head = tail = node;
            }
            else {
                tail->next = node;
                node->prev = tail;
                tail = node;
                tail->next = NULL;
            }
            size++;
        }
        struct DoubleList * pop_front(void) {
            struct DoubleList * node;
            node = head;

            if (size == 1) {
                head = tail = NULL;
            }
            else {
                head = head->next;
                head->prev = NULL;
            }
            
            size --;
            return node;
        }
    };    
    unordered_map<int, struct DoubleList *> gkvmap;
    unordered_map<int, MyList *> gfreqmap;
    int max_cnt;
    int cnt;
    
    LFUCache(int capacity) {
        max_cnt = capacity;
        cnt = 0;
    }
    
    int get(int key) {
        if (this->max_cnt == 0 || gkvmap.find(key) == gkvmap.end()) return -1;
        
        struct DoubleList * target = gkvmap[key];
        int val  = target->val;
        int freq = target->freq;
        
        MyList * lrulist = gfreqmap[freq];

        //remove target from lrulist
        lrulist->remove(target);
        if (lrulist->empty()) {
            delete(lrulist);
            gfreqmap.erase(freq);
        }
        
        //move target to the higher freq's lrulist
        target->freq ++;
        freq = target->freq;
        if (gfreqmap.find(freq) == gfreqmap.end()) {
            gfreqmap[freq] = new MyList();
        }
        lrulist = gfreqmap[freq];
        lrulist->push_back(target);
        
        return val;
    }
    
    void put(int key, int value) {
        
        if (0 == this->max_cnt) return;
        
        struct DoubleList * target = NULL;
        int freq;
        
        if (gkvmap.find(key) == gkvmap.end()) {  //entering a new key

            if (this->cnt == this->max_cnt) {
                //start eviction
                //search the least freq from all keys from gfreqmap
                int min_f = INT_MAX;
                for (auto it : gfreqmap) {
                    min_f = min(min_f, it.first);
                }

                if (min_f != INT_MAX) {
                    MyList * lrulist = gfreqmap[min_f];
                    target = lrulist->pop_front(); //evict the oldest one from the list
                    if (lrulist->empty()) {
                        delete lrulist;
                        gfreqmap.erase(min_f);
                    }
                    gkvmap.erase(target->key);
                    delete target;
                    this->cnt--;
                }
            }

            //new key, create new target
            target = new DoubleList(key, value, 1, NULL, NULL);
            gkvmap[key] = target;

            freq = target->freq;

            if (gfreqmap.find(freq) == gfreqmap.end()) {
                gfreqmap[freq] = new MyList();
            }
            MyList * lrulist = gfreqmap[freq];
            lrulist->push_back(target);
            this->cnt++;

        }
        else {
            //updating an existing key, 
            target = gkvmap[key];
            target->val = value;
            get(key); //move it to upper freq lrulist
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */