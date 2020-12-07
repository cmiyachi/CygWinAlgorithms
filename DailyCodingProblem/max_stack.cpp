#include <bits/stdc++.h>
using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {
	private:
		stack<int> stack_num;
		stack<int> stack_min;
		stack<int> stack_max; 
	
public:
  int peek() {
    // Write your code here.
		
    return stack_num.empty() ? -1 : stack_num.top(); 
  }

  int pop() {
    // Write your code here.
		int num = -1;
		
		if (stack_num.size() != 0)
		{
			num = stack_num.top();
		stack_num.pop();
		stack_min.pop();
		stack_max.pop();
		}
    return num; 
  }

  void push(int num) {
    // Write your code here.
		if (stack_num.size() == 0) 
		{
			stack_num.push(num);
			stack_min.push(num);
			stack_max.push(num);
			return; 
		}
		if (num > stack_max.top())
			stack_max.push(num);
		else
			stack_max.push(stack_max.top()); 
		
		if (num < stack_min.top())
			stack_min.push(num);
		else
			stack_min.push(stack_min.top());
		
		stack_num.push(num);
		
  }

  int getMin() {
    // Write your code here.
    return stack_num.empty() ? INT_MAX : stack_min.top();
  }

  int getMax() {
    // Write your code here.
    return stack_num.empty() ? INT_MIN : stack_max.top();
  }
};

int main(void)
{
	MinMaxStack mms;
	mms.push(100);
	mms.push(10);
	mms.push(200);
	mms.push(50);
	mms.push(40);
	mms.push(300);
	
	cout << mms.getMax() << endl;
	mms.pop();
	mms.pop();
	cout << mms.getMax() << endl;
	mms.pop();
	mms.pop();
	cout << mms.getMax() << endl;
	return 0;
	return 0;
}