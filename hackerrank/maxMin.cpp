#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    int result;
    sort(arr.begin(), arr.end());
    result = arr[k-1]-arr[0];
    for(unsigned int i = 1; i<arr.size()-k+1; i++){
        if(arr[i+k-1]-arr[i] < result)
            result = arr[i+k-1]-arr[i];
    }
    
    return result;
}

int main(void)
{
	vector<int> arra{1,2,3,4,10,20,30,40,100,200};
	cout << maxMin(4,arra); 
	
	return 0;
}