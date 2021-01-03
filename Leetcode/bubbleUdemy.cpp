#include <bits/stdc++.h>

using namespace std;

std::vector<int> bubbleSort2(std::vector<int> items) {

  int len = items.size();

  for (int i = 0; i < len; i++) {
    for (int j = 0, stop = len - i; j < stop - 1; j++) {
      if (items[j] > items[j + 1]) {
        std::swap(items[j], items[j + 1]);
      }
    }
  }

  return items;
}

void bubbleSort(vector<int>& a)
{
	int n = a.size();
	
	 for (int count = 1; count <= n-1; count++)
	 {
		 int flag = 0; // optimized!
		for (int j = 0; j <= n-2; j++)
		{
			if (a[j] > a[j+1]) {
				swap(a[j], a[j+1]);
				flag = 1; 
			}
		}
		if (flag = 0)
			break; 
	 }
}

int main(void)
{
	
	int n; 
	cin >> n;
	
	vector<int> a(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	// vector<int> items{2, 4, 1, 5};
	
	 bubbleSort(a);
	
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	
	return 0;
}