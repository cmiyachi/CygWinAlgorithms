
#include <bits/stdc++.h>
	
using namespace std; 

// Compares two intervals according to their staring time. 
	// This is needed for sorting the intervals using library 
	// function std::sort(). See http://goo.gl/iGspV 
	bool compareInterval(vector<int> i1, vector<int> i2) 
	{ 
		return (i1[0] < i2[0]); 
	} 
	

class Solution {
public:
	
	
	
   vector<vector<int>>  merge(vector<vector<int>>& intervals) {
			vector<vector<int>> results; 
		// Test if the given set has at least one interval 
		if (intervals.size() <= 0) 
			return results; 

		// Create an empty stack of intervals 
		stack<vector<int>> s; 

		// sort the intervals in increasing order of start time 
		sort(intervals.begin(), intervals.end(), compareInterval); 

		// push the first interval to stack 
		s.push(intervals[0]); 

		// Start from the next interval and merge if necessary 
		for (int i = 1 ; i < intervals.size(); i++) 
		{ 
			// get interval from stack top 
			vector<int> top = s.top(); 

			// if current interval is not overlapping with stack top, 
			// push it to the stack 
			if (top[1] < intervals[i][0]) 
				s.push(intervals[i]); 

			// Otherwise update the ending time of top if ending of current 
			// interval is more 
			else if (top[1] < intervals[i][1]) 
			{ 
				top[1]= intervals[i][1]; 
				s.pop(); 
				s.push(top); 
			} 
		} 

		// push contents of stack 
		
		while (!s.empty()) 
		{ 
			vector<int> t = s.top(); 
			results.push_back(t);
			// scout << "[" << t[0] << "," << t[1] << "] "; 
			s.pop(); 
		} 
		return results; 
			
			
		}
};



// Driver program 
int main() 
{ 
	vector<vector<int>> arr{ {6,8}, {1,9}, {2,4}, {4,7} }; 
	Solution sol;
	
	
	
	vector<vector<int>> results = sol.merge(arr);
	
	for (int i = 0; i < results.size(); i++)
	{
		cout << "[" << results[i][0] << "," << results[i][1] << "] "; 
	}
	
	return 0; 
} 
