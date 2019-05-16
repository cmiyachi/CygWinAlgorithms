#include <bits/stdc++.h>

using namespace std;

std::vector<int> bubbleSort(std::vector<int> items) {

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

int main(void)
{
	vector<int> items{2, 4, 1, 5};
	
	vector<int> results = bubbleSort(items);
	
	for (int i = 0; i < results.size(); i++)
		cout << results[i] << " ";
	
	return 0;
}