// Simple C++ program to print 
// next greater elements in a 
// given array 
#include<iostream> 
#include <vector> 
#include <stack>
#include <limits.h>
using namespace std; 

std::vector<int> nearestGreaterNaive(std::vector<int> a) {
	int next; 
	vector<int> b(a.size(), -1); 
	vector<int> distance(a.size(),INT_MAX); 
	
	for (int i = 0; i < a.size(); i++)
	{
		next = -1;
		for (int j = 0; j < a.size(); j++)
		{
			if (a[i] < a[j])
			{
				if (abs(i-j) < distance[j])
				{
					next = a[j]; 
					distance[j] = abs(i-j); 
					b[i] = j; 
				}
				// break;
			}
		} // for j
		// if (next == -1) b.push_back(next); 
	}
	return b; 
}

std::vector<int> nearestGreater(std::vector<int> a) 
{
    vector<int> b(a.size(), -1);
    stack<int> st; // stack will contain the indices.
    
    // go from beginning
    for(int i = 0 ; i < a.size(); i++)
    {
        while(!st.empty() && a[i] >= a[st.top()])
        {
            st.pop();
        }
        if(!st.empty())
            b[i] = st.top();
        st.push(i);
    }
    
    // clean the stack
    while(!st.empty())
        st.pop();
    
    // go from end
    for(int i = a.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && a[i] >= a[st.top()])
        {
            st.pop();
        }

        if(!st.empty())
        {
            if(b[i] == -1 || abs(i - st.top()) < abs(i - b[i]))
                b[i] = st.top();
        }
        st.push(i);
    }
    return b;
}
// Driver Code 
int main() 
{ 
	vector<int> a{11, 13, 21, 3}; 
	vector<int> b = nearestGreater(a); 
	
	for (int i = 0; i < a.size(); i++)
		cout << b[i] << endl; 
	
	vector<int> c = nearestGreaterNaive(a); 
	for (int i = 0; i < a.size(); i++)
		cout << c[i] << endl; 
	return 0; 
} 

 
