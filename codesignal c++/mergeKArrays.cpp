#include <bits/stdc++.h>

using namespace std;

std::vector<int> mergeKArrays(std::vector<std::vector<int>> arrays) {
  std::vector<int> firstUnused(arrays.size(), 0),
                   result;
  int n = 0;
  for (int i = 0; i < arrays.size(); i++) {
    n += arrays[i].size();
  }
  for (int i = 0; i < n; i++) {
    int minIndex = -1,
        minValue = 0;
    for (int j = 0; j < arrays.size(); j++) {
      if (firstUnused[j] < arrays[j].size()) {
        if ( minIndex == -1 || minValue > arrays[j][firstUnused[j]] ) {
          minIndex = j;
          minValue = arrays[j][firstUnused[j]];
        }
      }
    }
    result.push_back(minValue);
    firstUnused[minIndex]++;
  }
  return result;
}

int main(void) {

    /*
    std::vector<std::vector<int>> arrays = {
            std::vector({1, 3, 5, 7}),
            std::vector({2, 4, 6, 8})
    };
     */

    std::vector<std::vector<int>> arrays = {
            {1, 3, 5, 7},
            {2, 4, 6, 8},
            {9}
    };

    std::vector<int> result = mergeKArrays(arrays);
    std::for_each(result.begin(), result.end(), [](auto item) {
        std::cout << item << " ";
    });
}
