#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long long candies(int n, vector<long> arr) {
	
 vector<long long> dp(n,1); 
 long long sum_of_elems = 0; 
 
 for(int i = 1 ; i < n  ;i++){ //forward track
        if(arr[i] > arr[i-1]){
            dp[i] = dp[i] + dp[i-1]; 
        }
    }

    for(int i = n-2 ; i >= 0 ; i--){ // back track
        if(arr[i] > arr[i+1] && dp[i] <= dp[i+1]){
            dp[i] = dp[i+1] + 1;
        }
    }
	for (auto& n : dp)
		sum_of_elems += n;
	
	return sum_of_elems; 
}

int main()
{
   //  ofstream cout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    cout << result << "\n";

   //  cout.close();

    return 0;
}
