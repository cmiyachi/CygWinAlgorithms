#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
    //Deletion, T = (1 + 2 + 3 + ... + n) * (1 / n) = 2
    //Armotized O(1), but can be as long as O(n) if get the last item.
private:
    unordered_map<int, int> hash;
    int size;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        hash.clear();
        size = 0;
        srand((int)time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        int existed = (hash.find(val) != hash.end());
        if(!existed){
            hash[val] = 1;
            size++;
        }
        return !existed;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        int existed = (hash.find(val) != hash.end());
        if(existed){
            hash.erase(val);
            size--;
        }
        return existed;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(size == 0)
            return 0;
        int index = rand() % size;
        auto it = hash.begin();
        while(index-- > 0){
            it++;
        }
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
 
 int main(void)
 {
	RandomizedSet *obj = new RandomizedSet();
	int val = 2; 
	int val1 = 3; 
	bool param_1 = obj->insert(val);
	bool param_2 = obj->remove(val1);
	int param_3 = obj->getRandom();
	 
	 cout << "insert " << param_1 << " remove " << param_2 << " random " << param_3;
	 
	 
	 return 0;
 }