// A user defined stack that supports getMin() in 
// addition to push() and pop() 

#include <bits/stdc++.h>

using namespace std;
	
class MinStack2 {

public:
    void push(int x) {
        curSta.push(x);
        if(minSta.empty() || x<=minSta.top() )
           minSta.push(x);
    }

    void pop() {
       
        if(minSta.top() == curSta.top() )
            minSta.pop();
        curSta.pop(); //Note: this line should be put in last, otherwise, the above codes can not be compared!!!!       
    }

    int top() {
        return curSta.top();
    }

    int getMin() {
        return minSta.top();
    }
   
private:
    stack<int> minSta;
    stack<int> curSta;   
};

class MinStack {

public:
    void push(int x) {
        /* If the stack is empty, then the min value
         * must just be the first value we add. */
        if (minSta.empty()) {
			vector<int> newItem{x,x};
            minSta.push(newItem);
            return;
        }
        
        vector<int> currentMin = minSta.top();
		int thisMin = currentMin[1]; 
		int the_min = min(x, thisMin);
		vector<int> item_to_push{x,the_min}; 
        minSta.push(item_to_push);
    }

    void pop() {
       
         minSta.pop();     
    }

    int top() {
		vector<int> the_top = minSta.top();
        return the_top[0];
    }

    int getMin() {
        vector<int> the_top = minSta.top();
        return the_top[1];
    }
   
private:
    stack<vector<int>> minSta; 
};

   
// Driver Code 
int main() 
{ 
	MinStack s; 
	s.push(3); 
	s.push(5); 
cout << 	s.getMin(); 
	s.push(2); 
	s.push(1); 
	 cout << s.getMin(); 
	s.pop(); 
cout << 	s.getMin(); 
	s.pop(); 
	cout << s.top(); 

	return 0; 
} 