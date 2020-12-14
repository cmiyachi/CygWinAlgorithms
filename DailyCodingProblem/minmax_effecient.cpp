#include <bits/stdc++.h>
using namespace std;

vector<int> compare(int x, int y)
{
	vector<int> result(2);
	
	if (y > x) 
	{
		result[0] = x; result[1] = y;
	}
	else
	{
		result[0] = y; result[1] = x;
	}
	
	return result;
}

vector<int> min_and_max(vector<int> array)
{
	int min_element = array[0];
	int max_element = array[1]; 
	
	if (array.size() % 2 == 0)
		array.push_back(-1); // make array have odd number so pair ups are neat
	
	for (int i = 1; i < array.size(); i=i+2)
	{
		vector<int> r = compare(array[i], array[i+1]);
		min_element = min(min_element, r[0]); 
		max_element = max(max_element, r[1]); 
	}
	
	vector<int> result{min_element, max_element};
	
	return result;
}
void print_vector(vector<int> x)
{
	for (int y : x)
		cout << y << " ";
		
	cout << endl;
}
vector<int> min_and_max2(vector<int> array)
{
	vector<int> result(2,0);
	if (array.size() == 1)
	{
		result[0] = array[0];
		result[1] = array[0];
		return result;
	}
	
	else if (array.size() == 2)
	{
		if(array[0] < array[1])
			result = {array[0], array[1]};
		else
			result = {array[1], array[0]};
		return result; 
	}
	else
	{
		int n = array.size()/2;
		vector<int> lnums(array.begin(), array.begin()+n);
		print_vector(lnums);
		vector<int> lresult = min_and_max2(lnums);
		vector<int> rnums(array.begin()+n, array.end()); 
		print_vector(rnums);
		vector<int> rresult = min_and_max2(rnums); 
		
		result[0] = min(lresult[0], rresult[0]);
		result[1] = max(lresult[1], rresult[1]); 
	}
	
	return result; 
}

int main(void)
{
	vector<int> num{4,2,7,5,-1,3,6};
	
	vector<int> r = min_and_max(num);
	
	for (int x : r)
		cout << x << " "; 
		
	cout << endl;
	
	r.clear();
	r = min_and_max2(num);
	for (int x : r)
		cout << x << " "; 
	
	return 0;
}