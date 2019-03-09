#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {

	int N = a.size(); 
	
	for (int n = 0; n <= N-2; n++)
	// for (int n = N-2; n >= 0; n--)
		for (int m = (n+1); m <= (N-1); m++)
		{
			int temp = a[n][m];
			a[n][m] = a[m][n];
			a[m][n] = temp; 
		}
		
	// for(int i=0; i<=N-2; i++) {
		// for(int j=i+1; j<=N-1; j++) {
   // //     new_data[i][j] = old_data[rows-1-j][i];
			// int temp = a[i][i];
			// a[i][j] = a[N-1-j][i];
			// a[N-1-j][i] = temp;
		// }
	// }		
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
							
	vector<vector<int>> b = rotateImage(c);
	
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