#include <bits/stdc++.h>

using namespace std;

// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
  
long maximumSum(vector<long> a, long m) {
  pair<long, long> apair[a.size()];
    int n = a.size();
    apair[0].first = a[0]%m; apair[0].second=1;
    long maxv = apair[0].first;
    for (int i = 1; i < n; i++) {
        apair[i].first = (a[i]%m + apair[i-1].first%m)%m;
        apair[i].second=i+1;
        if (maxv < apair[i].first) maxv = apair[i].first;
    }
    std::sort(apair,apair+n);

    std::cout << std::endl;    
    long minv= INT_MAX;
    for (int i = 0; i < n-1; i++) {
        if (apair[i].second > apair[i+1].second) {
            if ((apair[i+1].first-apair[i].first) < minv)
                minv = (apair[i+1].first-apair[i].first);
        }
    }
    return std::max<long>(maxv, m-minv);
}

int main(void)
{
	int m = 7;
	vector<long> a{3, 3, 9, 9 ,5};
	
	cout << maximumSum(a,m); 
	return 0;
}