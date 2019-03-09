#include <iostream>
#include <vector>
#include <set>



using namespace std;

int firstDuplicate(vector<int> a) {
    
    set<int> unique_values;
	int min_index = -1;
    
    for (int i= 0; i < a.size(); i++)
	{
		if (unique_values.find(a[i]) != unique_values.end())
		{
			
			min_index = i;
			break;
		}
		else
		{
			unique_values.insert(a[i]);
		}
	
	}
	
	return ((min_index == -1) ? min_index : a[min_index]);
	
	
}

int main()
{
	vector<int>  a = {2, 1, 3, 5, 3, 2};
	
	cout <<  firstDuplicate(a);
	
	return 0;
	
}
	
	
