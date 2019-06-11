// C++ program to generate n-bit Gray codes 
#include <iostream> 
#include <string> 
#include <vector> 
using namespace std; 

// This function generates all n bit Gray codes and prints the 
// generated codes 
vector<int> grayCode(int n) 
{ 
	vector<int> res; 
	
	// base case 
	if (n <= 0){
		res.push_back(0); 
		return res;
	}		

	// 'arr' will store all generated codes 
	vector<string> arr; 

	// start with one-bit pattern 
	arr.push_back("0"); 
	arr.push_back("1"); 

	// Every iteration of this loop generates 2*i codes from previously 
	// generated i codes. 
	int i, j; 
	for (i = 2; i < (1<<n); i = i<<1) 
	{ 
		// Enter the prviously generated codes again in arr[] in reverse 
		// order. Nor arr[] has double number of codes. 
		for (j = i-1 ; j >= 0 ; j--) 
			arr.push_back(arr[j]); 

		// append 0 to the first half 
		for (j = 0 ; j < i ; j++) 
			arr[j] = "0" + arr[j]; 

		// append 1 to the second half 
		for (j = i ; j < 2*i ; j++) 
			arr[j] = "1" + arr[j]; 
	} 

	// print contents of arr[] 
	//for (i = 0 ; i < arr.size() ; i++ ) 
	////	cout << arr[i] << endl; 
	
	for(int i=0;i<arr.size();++i)
		{
			int num = stoi(arr[i],0,2);
			res.push_back(num);
		}
	//for (int i = 0 ; i < res.size() ; i++ ) 
	//	cout << res[i] << endl;
	
	return res; 
} 

  
        
    
// Driver program to test above function 
int main() 
{ 
	vector<int> res = grayCode(3); 
	
	for (int i = 0 ; i < res.size() ; i++ ) 
		cout << res[i] << endl;
	return 0; 
} 
