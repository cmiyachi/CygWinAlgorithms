#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>



using namespace std;

// Complete the minimumAbsoluteDifference function below.
void print_vec(vector<int> arr){
    for(int n:arr) cout << n << endl;
}

int minimumAbsoluteDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int min = abs(arr[1]-arr[0]);
    // cout << min << endl;
    for(int i = 1; i < arr.size(); i++){
        int x = abs(arr[i+1] - arr[i]);
        if(min > x) min = x;
    }
    return min;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n);

    for(int i=0; i<n; i++) cin >> arr[i];
    int result = minimumAbsoluteDifference(arr);

    cout << result << "\n";
    return 0;
}