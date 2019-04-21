#include <iostream>
#include <vector>

// Complete the hourglassSum function below.
int hourglassSum(std::vector<std::vector<int>> arr) 
{
	int hourglassSum = 9999;

	for(auto i = 1; i < 5; ++i)
	{
		for(auto j = 1; j < 5; ++j)
		{
			const auto center = arr[i][j];
			const auto sum = center + arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1] +
				arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1];
			if(hourglassSum == 9999) hourglassSum = sum;
			else if(sum > hourglassSum) hourglassSum = sum;
		}
	}

	return hourglassSum;
}

int main()
{
	const std::vector<std::vector<int>> arr = { {1,1,1,0,0,0}, { 0,1,0,0,0,0 }, { 1,1,1,0,0,0 }, { 0,0,2,4,4,0 }, { 0,0,0,2,0,0 }, { 0,0,1,2,4,0 }};
	int result = hourglassSum(arr);
	std::cout << result;

	return 0;
}