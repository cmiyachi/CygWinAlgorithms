#include <iostream>
#include <algorithm>
#include <vector> 
#include <cmath> 

using namespace std;

std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {

	int n = a.size(); 
	int x = floor(n/ 2);
	int y = n - 1;
	for (int i = 0; i < x; i++) {
     for (int j = i; j < y - i; j++) {
        int k = a[i][j];
        a[i][j] = a[y - j][i];
        a[y - j][i] = a[y - i][y - j];
        a[y - i][y - j] = a[j][y - i];
        a[j][y - i] = k;
     }
  }	
return a; 
}

int main()
{

	vector<vector<int>> a = {{1,2,3}, 
							{4,5,6}, 
							{7,8,9}};
							
	vector<vector<int>> c = {{10,9,6,3,7}, 
 {6,10,2,9,7}, 
 {7,6,3,8,2}, 
 {8,9,7,9,9}, 
 {6,8,6,8,2}};
							
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