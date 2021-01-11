#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
        if(s2.empty()) s2.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = s2.top();
        s2.pop();
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        if(!s2.empty()){
            int newfirst = s2.top();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            s2.push(newfirst);
        }
        return tmp;         
    }
    
    /** Get the front element. */
    int peek() {
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class Quack {
	public:
  
     int sz;
     stack<int> s1, s2, s3;

     Quack() {
        s1={};
        s2={};
        s3={};
    }

    /*
        when adding new element on left end, do it to both s1 and s2
     */
     void push(int v) {
        s1.push(v);
        s2.push(v);
        sz++;
    }

    /*
        when poping from left end, if there is no element left, throw exception;
        otherwise, pop on s2 and s1.
     */
int pop() {
        if(sz == 0) {
			while(!s1.empty())
				s1.pop();
            while(!s3.empty())
				s3.pop();
            return -1; 
        }
        s2.pop();
        sz--;
		int val = s1.top(); s1.pop();
        return val;
    }

    /*
        when popping from right end, if there is no element left, throw exception;
        otherwise, check if there are elements in s3. If there are, simply pop;
        If there is none, reverse all elements in s2 to s3, then pop from s3.
     */
     int pull() {
        if(sz == 0) {
            while(!s1.empty())
				s1.pop();
            while(!s3.empty())
				s3.pop();
			return -1; 
        }
        else if(s3.size() == 0) {
            while(s2.size() > 0) {
                s3.push(s2.top());
				s2.pop();
            }
        }
        sz--;
        int val = s3.top(); s3.pop();
        return val;
    }
	
	
};
class Quack2 {
	public:
  
     int sz;
     deque<int> dq;

     Quack2() {
        dq={};
		sz = dq.size();
    }

    /*
        when adding new element on left end, do it to both s1 and s2
     */
     void push(int v) {
        dq.push_front(v);
        sz++;
    }

    /*
        when poping from left end, if there is no element left, throw exception;
        otherwise, pop on s2 and s1.
     */
int pop() {
        if (dq.size() == 0) return -1; 
		int val = dq.front();
		dq.pop_front();
		sz--;
		return val; 
     
    }

    /*
        when popping from right end, if there is no element left, throw exception;
        otherwise, check if there are elements in s3. If there are, simply pop;
        If there is none, reverse all elements in s2 to s3, then pop from s3.
     */
     int pull() {
        if (dq.size() == 0) return -1; 
        sz--;
        int val = dq.back();
		dq.pop_back();
        return val;
    }
	
	
};
/**
public class BalancedQuack {
    private class EmptyQuackException extends Exception{
        String error = "Empty Quack Exception!";
    }

    private Stack<Integer> left, right, auxillary;

    public BalancedQuack() {
        left = new Stack<>();
        right = new Stack<>();
        auxillary = new Stack<>();
    }

    public void push(int v) {
        left.push(v);
    }

    public int pop() throws EmptyQuackException {
        if(left.size() == 0 && right.size() == 0) {
            throw new EmptyQuackException();
        }
        else if(left.size() == 0) {
            for(int i = 0; i < right.size() / 2; i++) {
                auxillary.push(right.pop());
            }
            while(right.size() > 0) {
                left.push(right.pop());
            }
            while(auxillary.size() > 0) {
                right.push(auxillary.pop());
            }
        }
        return left.pop();
    }

    public int pull() throws EmptyQuackException {
        if(left.size() == 0 && right.size() == 0) {
            throw new EmptyQuackException();
        }
        else if(right.size() == 0) {
            for(int i = 0; i < left.size() / 2; i++) {
                auxillary.push(left.pop());
            }
            while(left.size() > 0) {
                right.push(left.pop());
            }
            while(auxillary.size() > 0) {
                left.push(auxillary.pop());
            }
        }
        return right.pop();
    }
} **/

int main(void)
{
	Quack q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << q.pull() << endl;
	cout << q.pop() << endl;
	
	Quack2 q2;
	q2.push(1);
	q2.push(2);
	q2.push(3);
	q2.push(4);
	q2.push(5);
	cout << q2.pull() << endl;
	cout << q2.pop() << endl;
	
	return 0;
}


