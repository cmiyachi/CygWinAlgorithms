#include <bits/stdc++.h>
using namespace std;



int findIndex(vector<int>& arr, int v) {
    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] == v) return i; 
    return -1;
}


int findMaxIndex(vector<int>& arr, int v) {
	int max_val = INT_MIN;
	int max_index = -1; 
    for (int i = 0; i < v; ++i)
        if (arr[i] > max_val) {
			max_val = arr[i]; 
			max_index = i;
		}
    return max_index; 
}

void flip(vector<int>& arr, int k) {
    for (int l = 0, r = k; l <= r;) swap(arr[l++], arr[r--]);
}

void reverse_vector(vector<int> &array, int i, int j)
{
	reverse(array.begin()+i, array.begin()+j);
}

vector<int> pancakeSort(vector<int>& arr) {
    vector<int> ans;
    for (int v = arr.size(); v >= 1; --v) {
        int index = findIndex(arr, v);
        if (index == v - 1) continue;
        if (index != 0) {
            ans.push_back(index + 1);
            flip(arr, index);
        }
        ans.push_back(v);
        flip(arr, v - 1);
    }
    return ans;
}

vector<int> pancake_sort(vector<int>& arr) {
    vector<int> ans;
    for (int v = arr.size(); v >= 1; --v) {
        int index = findMaxIndex(arr, v);
        if (index == v - 1) continue;
        if (index != 0) {
            ans.push_back(index + 1);
            flip(arr, index);
        }
        ans.push_back(v);
        flip(arr, v - 1);
    }
    return ans;
}

int main(void)
{
	vector<int>  array{50,10, 40,20, 30};
	vector<int> result = pancake_sort(array);
	
	for (int x: result)
		cout << x << " ";
	cout << endl;
	for (int x: array)
		cout << x << " "; 
		
	return 0;
}