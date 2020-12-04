#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> zerosToEnd(vector<int> nums);

vector<int> zerosToEnd(vector<int> nums)
{
    auto insert_pos = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0)
            nums[insert_pos++] = nums[i];
    }

    for (int j = insert_pos; j < nums.size(); j++)
        nums[j] = 0;

    return nums;

}

int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> nums{1,0,2,0,4,0};
    nums = zerosToEnd(nums);
    for (int n : nums)
        cout << n << " ";
    cout << endl;

    return 0;
}
