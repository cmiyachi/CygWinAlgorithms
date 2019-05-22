#include <bits/stdc++.h>

using namespace std;

std::vector<int> sortedSquaredArray(std::vector<int> array) {
	
    int j = 0, n = array.size();
	vector<int> result; 
	
    // Find the last index of the negative numbers
    while (j < n && array[j] < 0)
        j++;

    // i points to the last index of negative numbers
    int i = j-1;

    int t = 0;
    // j points to the first index of the positive numbers
    while (i >= 0 && j < n) {
        if (array[i] * array[i] < array[j] * array[j]) {
            result.push_back(array[i] * array[i]);
            i--;
        } else {
            result.push_back(array[j] * array[j]);
            j++;
        }
    }
    // add the remaining negative numbers squares to result
    while (i >= 0) {
        result.push_back(array[i] * array[i]);
        i--;
    }

    // add the remaining positive numbers squares to result
    while (j < n) {
        result.push_back(array[j] * array[j]);
        j++;
    }
  	
	return result; 

}

int main(void)
{
	vector<int> array{-6, -4, 1, 2, 3, 5};
	
	vector<int> result = sortedSquaredArray(array);
	
	for (int i = 0; i < array.size(); i++)
	{
		cout << result[i] << " "; 
	}
	
	return 0;
}