#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
#if 0 // TIMEOUT: O(n^2)
long largestRectangleSlow(vector<int> h) {
    int n = h.size();
    long max_area = 0;    
        
    for (int i = 0; i < n; ++i) {        
        int min_h = h[i];
        for (int j = i; j < n; ++j) {
            min_h = min(h[j], min_h);
            long area = (long)(j - i + 1) * (long)min_h;
            max_area = max(area, max_area);
        }
    }
    return max_area;
}
#else
long largestRectangleFast(vector<int> h) {
    long max_area = 0;
    stack<vector<int>> s; // stack of {height, left_index}

    h.push_back(0);
    s.push({h[0], 0});
    for (int i = 1; i < h.size(); ++i) {
        if (h[i] >= h[i-1]) {
            s.push({h[i], i});
        } else {
            int left_idx = i;
            while (!s.empty() && s.top()[0] >= h[i]) {
                left_idx = s.top()[1];  
                long area = s.top()[0] * (i - s.top()[1]);       
                max_area = max(area, max_area);
                s.pop();
            }
            s.push({h[i], left_idx});
        }
    }

    return max_area;
}
#endif

// The main function to find the maximum rectangular  
// area under given histogram with n bars 
long getMaxArea(vector<int> hist) 
{ 
	int n = hist.size(); 
    // Create an empty stack. The stack holds indexes  
    // of hist[] array. The bars stored in stack are  
    // always in increasing order of their heights. 
    stack<int> s; 
  
    long max_area = 0; // Initalize max area 
    int tp;  // To store top of stack 
    int area_with_top; // To store area with top bar 
                       // as the smallest bar 
  
    // Run through all bars of given histogram 
    int i = 0; 
    while (i < n) 
    { 
        // If this bar is higher than the bar on top  
        // stack, push it to stack 
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++); 
  
        // If this bar is lower than top of stack,  
        // then calculate area of rectangle with stack  
        // top as the smallest (or minimum height) bar.  
        // 'i' is 'right index' for the top and element  
        // before top in stack is 'left index' 
        else
        { 
            tp = s.top();  // store the top index 
            s.pop();  // pop the top 
  
            // Calculate the area with hist[tp] stack  
            // as smallest bar 
            area_with_top = hist[tp] * (s.empty() ? i :  
                                   i - s.top() - 1); 
  
            // update max area, if needed 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
  
    // Now pop the remaining bars from stack and calculate 
    // area with every popped bar as the smallest bar 
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = hist[tp] * (s.empty() ? i :  
                                i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
} 
 
 long largestRectangle(vector<int> h) {
    long result = getMaxArea(h); 
	
	return result; 
 }
// Driver program to test above function 
int main(void)
{
	vector<int> hist{1, 2, 3, 4 ,5};
	cout << largestRectangle(hist); 
	return 0;
}