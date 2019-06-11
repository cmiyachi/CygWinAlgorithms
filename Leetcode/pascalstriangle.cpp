
#include <bits/stdc++.h>
using namespace std;

/* int pascal(const int n, const int x)
{
    if(n == 0 || n == 1 || x == 0 || x == n)
        return 1;
    return pascal(n-1, x-1) + pascal(n-1, x);
}

vector<int> getRow(int rowIndex) {
	int coef=1,i,j;
	rowIndex++; 
	vector<int> res; 
	for(int i=0;i<rowIndex;++i){
        for(int x=0;x<=i;++x){
			if (i == (rowIndex -1))
				res.push_back(pascal(i, x));  
        }
    }
	
	return res; 
  */       
}

 vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        //fill(row.begin(), row.end(), 1);
        
        for (int i = 2; i <= rowIndex; ++ i) {
            for (int j = i - 1; j > 0; -- j) { // backward !
                row[j] += row[j - 1];
            }
        } 
        
        return row;
    }
int main(void)
{
	vector<int> res = getRow(5); 
	
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " "; 
	return 0;
}