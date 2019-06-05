#include <bits/stdc++.h>

using namespace std;
long triplets(vector<int> a, vector<int> b, vector<int> c) {
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
 
    a.erase(unique(a.begin(),a.end()),a.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    
    int i = 0, j = 0, k = 0;
    long sol=0;
    
    while(i < b.size()){
        while(a[j]<=b[i] && j<a.size())
            j++;
        while(c[k]<=b[i] && k<c.size())
            k++;
        sol+= (long)j*k;
        i++;
    }
    return sol;
}

int main(void)
{
	vector<int> a{1, 4, 5};
	vector<int> b{2, 3, 3};
	vector<int> c{1, 2, 3};
	
	cout << triplets(a,b,c); 
	return 0;
}