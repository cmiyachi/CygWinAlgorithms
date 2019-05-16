#include <bits/stdc++.h>

using namespace std;

void quickSortWithReference(std::vector<int>& a, int l, int r) {
  if (l >= r) {
    return;
  }

  int x = a[l];
  int i = l;
  int j = r;

  while (i <= j) {
    while (a[i] < x) {
      i++;
    }
    while (a[j] > x) {
      j--;
    }
    if (i <= j) {
      int t = a[i];
      a[i] = a[j];
      a[j] = t;
      i++;
      j--;
    }
  }

  quickSortWithReference(a, l, j);
  quickSortWithReference(a, i, r);
}

std::vector<int> quickSort(std::vector<int> a, int l, int r) {
  quickSortWithReference(a, l, r);
  return a;
}

int main(void)
{
	vector<int> array{3, 6, 1, 5, 3, 6};
	
	vector<int> result = quickSort(array, 0, array.size()); 
	
	for (int i = 0; i < result.size(); i++)
		cout <<  result[i] << " ";
	
	
	return 0;
}
