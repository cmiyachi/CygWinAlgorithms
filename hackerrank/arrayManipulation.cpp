//This code fails to consider big operations and timed out. Solution given below gives proper result
#include <bits/stdc++.h>
#include<vector>
using namespace std;

// Complete the arrayManipulation function below.
long arrayManipulation(long n, vector<vector<long>> queries) {
    vector<long> starterVector(n, 0);
    for (int i = 0; i < queries.size(); i++)
    {
        // Current manipulation
        long valueToAdd = queries[i].back();
        int firstIndex = queries[i][queries[i].size() - 3] - 1;
        int lastIndex = queries[i][queries[i].size() - 2] - 1;
        starterVector[firstIndex] += valueToAdd;
        starterVector[lastIndex + 1] -= valueToAdd;
    }
    long long sum = 0;
    long long max = 0;
    for (int i = 0; i < n; ++i)
    {
        sum = sum + starterVector[i];
        if (max < sum)
        {
            max = sum;
        }
    }
    return max;
}

int main()
{
    vector<vector<long>> queries;
    long n,m;
    cin>>n>>m;
    long temp;
    for(long i=0;i<m;i++){
        vector<long> row;
        for(long j=0;j<3;j++){
            cin>>temp;
            row.push_back(temp);
        }
        queries.push_back(row);
    }
    long result=arrayManipulation(n,queries);
    cout<<result;
    return 0;
}