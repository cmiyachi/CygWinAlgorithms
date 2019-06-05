#include <bits/stdc++.h>

using namespace std;

bool sumOfTwo(std::vector<int> a, std::vector<int> b, int v) {
	
	/* for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i]+b[j] == v) return true;
		}
		
	return false; */ 
	sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (auto &num : a)
    {
        if (binary_search(b.begin(), b.end(), v - num))
            return true;
    }

    return false;
}

int main(void)
{
	vector<int> a{1,2,3};
	vector<int> b{10,20, 30, 40};
	
	cout << sumOfTwo(a,b, 42); 
	return 0; 
}