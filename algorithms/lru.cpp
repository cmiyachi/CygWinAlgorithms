// Implementation of LRU Cache using two data structures:
// 1. Doubly Linked List
// 2. HashMap
#include<bits/stdc++.h> 
using namespace std;

class LRUCache {
public:
    int cacheSize;
    map<int, int> m;
    deque<int> dq;
    
    LRUCache(int capacity) {
        m.clear();
        dq.clear();
        cacheSize = capacity;
    }
    
	//function for printing the elements in a list 
	void show_deque() 
	{ 
		deque <int> :: iterator it; 
		for(it = dq.begin(); it != dq.end(); ++it) 
			cout << '\t' << *it; 
		cout << '\n'; 
	} 
  
    int get(int key) {
        // not found
        if (m.find(key) == m.end()) {
            return -1;
        } else {
            // found
            deque<int>::iterator it = dq.begin();
            while (*it != key) {
                it++;
            }
            
            // update queue: update it to most recent used value
            dq.erase(it);
            dq.push_front(key);
            
            return m[key];
        }
    }
    
    void put(int key, int value) {
        // not present in cache
        if (m.find(key) == m.end()) {
            // check if cache is full
            if (cacheSize == dq.size()) {
                int last = dq.back();
                dq.pop_back();
                m.erase(last);
            }
        } else {
            // present in cache, remove it from queue and map
            deque<int>::iterator it = dq.begin();
            while (*it != key) {
                it++;
            }
            
            dq.erase(it);
            m.erase(key);
        }
        
        // update the cache
        dq.push_front(key);
        m[key] = value;
    }
};

int main(void)
{
	LRUCache cache(2); 
	
	cache.put(1, 1);
	cache.put(2, 2);
	cache.show_deque();
	cout << cache.get(1) <<endl;;       // returns 1
	cache.show_deque();
	cache.put(3, 3);    // evicts key 2
	cache.show_deque();
	cout << cache.get(2) <<endl;;       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cout << cache.get(1)<<endl;      // returns -1 (not found)
	cache.show_deque();
	cout << cache.get(3)<<endl;       // returns 3
	cout << cache.get(4)<<endl;;       // returns 4
	cache.show_deque();
	
	return 0;
}