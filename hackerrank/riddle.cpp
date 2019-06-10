/* Given an integer array of size , find the maximum of the minimum(s) of every window size in the array. 
The window size varies from  to .

For example, given , consider window sizes of  through . 
Windows of size  are . The maximum value of the minimum values of these windows is . 
Windows of size  are  and their minima are . The maximum of these values is . 
Continue this process through window size  to finally consider the entire array. All of the answers are .
https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
*/

#include <bits/stdc++.h>
using namespace std;

// Complete the riddle function below.
// Complete the riddle function below.
/* #if 0 // O(n^nlogn): TIMOEUT
vector<long> riddle(vector<long> arr) {
    // complete this function   
    vector<long> answer; 

    answer.push_back(*max_element(arr.begin(), arr.end()));
    for (int w = 2; w <= arr.size(); ++w) {
        // initialize max as first min in the window
        map<long, int> mh;        
        for (int i = 0; i < w; ++i) mh[arr[i]]++;            
        long a_max = mh.begin()->first; 

        for (int i = 0; i + w < arr.size(); ++i) {
            mh[arr[i]]--;
            if (mh[arr[i]] == 0) mh.erase(arr[i]);
            mh[arr[i + w]]++;
            a_max = max(mh.begin()->first, a_max);
        }

        answer.push_back(a_max);
    }
    return answer;
}
#elif 0 // O(n^2): TIMEOUT */
/* vector<long> riddle(vector<long> arr) {
    vector<long> ans;

    vector<long> last(arr.begin(), arr.end());
    ans.push_back(*max_element(last.begin(), last.end()));

    for (int w = 2; w <= arr.size(); ++w) {
        long max_v = INT_MIN;
        for (int pos = arr.size() - 1; pos - w + 1 >= 0; --pos) {
            long v = min(last[pos - 1], arr[pos]);
            max_v = max(v, max_v);
            last[pos] = v;
        }
        ans.push_back(max_v);
    }
    return ans;
}
#endif // O(n) */
vector<long> riddle(vector<long> arr) {
    int n = arr.size();
    vector<int> left(n, -1); // index to the next element < a[i] on the left.
    vector<int> right(n, n); // index to the next element < a[i] on the right.
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            left[i] = s.top();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            right[i] = s.top();
        }
        s.push(i);
    }

    vector<long> ans(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int window = (right[i] - 1) - (left[i] + 1) + 1;
        ans[window] = max(arr[i], ans[window]);
    }

    for (int window = n - 1; window >= 1; --window) {
        ans[window] = max(ans[window], ans[window + 1]);
    }
    ans.erase(ans.begin());
    return ans;
}

int main(void)
{
	vector<long> data{3, 5, 4, 7, 6, 2};
	
	vector<long> result;

		result = riddle(data); 
		
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << " "; 
	
	return 0;
}