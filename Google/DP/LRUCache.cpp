
#include <bits/stdc++.h>

using namespace std;

/* class LRUCache {
	private:
		int cache_capacity;
		map<int, int> cache; 
		queue<int> LRU; 
public:
    LRUCache(int capacity) {
        cache_capacity = capacity; 
    }
    
    int get(int key) {
		
		auto itr = cache.find(key);
		if (itr != cache.end())
			return itr->second; 
		else
			return -1; 
        
    }
    
    void put(int key, int value) {
		cache.insert({key,value}); 
		LRU.push(key); 
		
		if (cache.size() == cache_capacity)
		{
			int key_to_remove = LRU.front(); 
			LRU.pop(); 
			auto itr = cache.find(key_to_remove);
			cache.erase(itr); 
		}
			
        return; 
    }
}; */
class LRUCache2 {
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            int value = mp[key]->second;
            lt.splice(lt.begin(), lt, mp[key]);
            return value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            get(key);
        } else {
            lt.emplace_front(key,value);
            mp[key] = lt.begin();
            if (lt.size() > size) {
                mp.erase(lt.back().first);
                lt.pop_back();
            }
        }
    }
    
private:
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int,int>> lt;
    int size;
    
};

class LRUCache{
    size_t m_capacity;
    unordered_map<int,  list<pair<int, int>>::iterator> m_map; //m_map_iter->first: key, m_map_iter->second: list iterator;
    list<pair<int, int>> m_list;                               //m_list_iter->first: key, m_list_iter->second: value;
public:
    LRUCache(size_t capacity):m_capacity(capacity) {
    }
    int get(int key) {
        auto found_iter = m_map.find(key);
        if (found_iter == m_map.end()) //key doesn't exist
            return -1;
        m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
        return found_iter->second->second;                         //return value of the node
    }
    void set(int key, int value) {
        auto found_iter = m_map.find(key);
        if (found_iter != m_map.end()) //key exists
        {
            m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
            found_iter->second->second = value;                        //update value of the node
            return;
        }
        if (m_map.size() == m_capacity) //reached capacity
        {
           int key_to_del = m_list.back().first; 
           m_list.pop_back();            //remove node in list;
           m_map.erase(key_to_del);      //remove key in map
        }
        m_list.emplace_front(key, value);  //create new node in list
        m_map[key] = m_list.begin();       //create correspondence between key and node
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 int main(void)
 {
	 int capacity = 3; 
	LRUCache* obj = new LRUCache(capacity);
	int key = 3; 
	int param_1 = obj->get(key);
	cout << param_1 << endl; 
	int value = 4; 
	obj->set(key,value);
	 obj->set(1	,2);
	 obj->set(2,3);
	 obj->set(4,6);
	 
	 cout << obj->get(4);
	 
	 delete obj; 
	return 0;
 }