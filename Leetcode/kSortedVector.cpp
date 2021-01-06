#include <bits/stdc++.h> 
using namespace std;

void kSortedArray(vector<int> &input, int k)
{
	int n = input.size();
	
	priority_queue<int>  pq;
	
	for (int i = 0; i < k; i++)
	{
		pq.push(input[i]); 
		
	}
	
	int s = 0; 
	for (int i = k; i < n; i++)
	{
		input[s] = pq.top();
		pq.pop();
		s++;
		pq.push(input[i]); 
	}
	
	while (!pq.empty())
	{
		input[s] = pq.top();
		pq.pop();
		s++;
	}
}

int main(void)
{
	vector<int> input{10,12,6,7,9};
	int k = 3; 
	
	kSortedArray(input, k);
	
	for (int x : input)
		cout << x << " "; 
	cout << endl;
	vector<int> input2{10,6,15,4,5};
	int k2 = 2; 
	
	kSortedArray(input2, k2);
	
	for (int x : input2)
		cout << x << " "; 	
		
		
		
	return 0;
}