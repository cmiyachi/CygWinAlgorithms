Skip to content
 
Search or jump to…

Pull requests
Issues
Marketplace
Explore
 
@cmiyachi 
1

    
#include <bits/stdc++.h>

using namespace std;

// Complete the stepPerms function below.
int stepPerms(int n) {
    //recursive solution. Leads to timeout in a few cases.
    /*int ans = 0;
    if (n==1 || n==0){
        return 1;
    }
    else if (n==2){
        return 2;
    }
    else{
        ans += stepPerms(n-1);
        ans += stepPerms(n-2);
        ans += stepPerms(n-3);
    }
    return ans;
    */

    //DP solution. Passes all test cases.
    vector<int> foo(n+1, 0);
    foo[0] = 1;
    foo[1] = 1;
    foo[2] = 2;
    for (int i = 3; i <=n; i++){
        foo[i] = foo[i-1] + foo[i-2] + foo[i-3];
    }

    return foo[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}

