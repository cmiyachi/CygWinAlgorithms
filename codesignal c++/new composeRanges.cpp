#include <bits/stdc++.h>

using namespace std;

std::vector<std::string> composeRanges(std::vector<int> nums) {
  vector<string> result;

  int n = nums.size();

  for (int i = 0; i < n; i++) {
    int start = nums[i];
    int end = start;

    while ((i < n - 1) && (nums[i + 1] - nums[i] == 1)) {
      end = nums[i + 1];
      i++;
    }

    ostringstream oss;
    oss << start;

    if (start != end) {
      oss << "->";
      oss << end;
    }

    result.push_back(oss.str());
  }

  return result;
}

int main(void)
{
	vector<int> nums{-1, 0, 1, 2, 6, 7, 9};
	
	vector<string> result = composeRanges(nums);
	
	for (int i = 0; i< result.size(); i++)
		cout << result[i] << " ";
	

	return 0;
	
}