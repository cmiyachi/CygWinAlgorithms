// A user defined stack that supports getMin() in 
// addition to push() and pop() 

#include <bits/stdc++.h>

using namespace std;
	
class MinStack {

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