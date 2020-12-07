#include <bits/stdc++.h>
using namespace std;

class SparseArray
{
	public:
	int n; // size
	unordered_map<int, int> dict; 
	
	SparseArray(vector<int> array, int n)
	{
		this->n = n;
		int m = array.size(); 
		if (m > n) m = n; 
		for (int i = 0; i < m;i++)
		{
			if (array[i] != 0)
				dict[i] = array[i]; 
		}
	}
	
	bool check_bounds(int index)
	{
		if (index < 0 || index >= n)
			return false;
		
		return true;
	}
	
	void set(int i, int val)
	{
		if (check_bounds(i))
		{
			if (val != 0)
				dict[i] = val; 
			else
				dict.erase(i); 
		}
	}
	
	int get(int i)
	{
		if (check_bounds(i))
		{
			if (dict.find(i) != dict.end())
				return dict[i];
		}
		
		return 0;
	}
};

int main(void)
{
	vector<int> arr{0,0,0,1,0,0,0,2,0,0,0,4};
	SparseArray *my_array = new SparseArray(arr, 13); 
	
	cout << my_array->get(14) << endl;
	cout << my_array->get(11) << endl;
	my_array->set(10,12);
	cout << my_array->get(10) << endl;
	return 0;
}
		