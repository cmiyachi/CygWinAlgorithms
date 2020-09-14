#include <bits/stdc++.h>
using namespace std;

class PhoneDirectory {
	private:
		set<int> unused;  // phone numbers unique
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; i++) {
			unused.insert(i);
		}
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        auto it = unused.begin();
		if (it == unused.end()) return -1;
		int res = *it;
		unused.erase(it);
		return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return !(unused.find(number) == unused.end());
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        unused.insert(number);
    }
};

int main(void){
	PhoneDirectory* obj = new PhoneDirectory(3);
	cout << obj->get() << endl;
	cout << obj->get() << endl;
	cout << obj->check(2) << endl;
	return 0;
}

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */