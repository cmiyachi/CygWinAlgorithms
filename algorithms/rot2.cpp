#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {

	int N = a.size();
	int temp;
	
	for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N / 2; j++)
        {
            temp = a[i][j];
            a[i][j] = a[i][N - 1 - j];
            a[i][N - 1 - j] = temp;
        }
	}

	a; 
}

int main()
{

	vector<vector<int>> a = {{1,2,3}, 
							{4,5,6}, 
							{7,8,9}};
							
	vector<vector<int>> b = rotateImage(a);
	
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < b[i].size(); j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
	
}