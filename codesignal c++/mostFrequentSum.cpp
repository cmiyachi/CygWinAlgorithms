#include <vector> 
#include <iostream> 
#include <map>

using namespace std;
//
// Definition for binary tree:
template<typename T>
struct Tree {
  Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
  T value;
  Tree *left;
  Tree *right;
};

map<int,int> total_sums;

int maxFreq(Tree<int> * t) {
	
	if (t == NULL)
		return 0;
	int left_side = maxFreq(t->left);
	int right_side = maxFreq(t->right);
	int total = t->value + left_side + right_side;
	
	if (total_sums[total] != 0)
		total_sums[total]++;
	else
		total_sums[total] = 1; 
	
	return total;

}
std::vector<int> mostFrequentSum(Tree<int> * t) {
	
	int total = maxFreq(t); 
	vector<int> results; 
	
	map<int, int>::iterator itr;
	int max = -1; 
	 for (itr = total_sums.begin(); itr != total_sums.end(); ++itr) { 
		if (itr->second > max)
			max = itr->second; 
    } 
    // cout << "max " << max << endl; 
	for (itr = total_sums.begin(); itr != total_sums.end(); ++itr) { 
		if (itr->second == max) {
			results.push_back(itr->first);
			//cout << "value " << itr->first << endl;
		}
    } 
	
	return(results); 
	
}
int main(void)
{
	const int value = 1; 
	Tree<int> t1(value); 
	Tree<int> t1left(2);
	Tree<int> t1right(3);
	t1.left = &t1left;
	t1.right = &t1right; 
	/* Tree<int> t1 = {
    "value": 1,
    "left": {
        "value": 2,
        "left": null,
        "right": null
    },
    "right": {
        "value": 3,
        "left": null,
        "right": null
    } */

/* 
t = {
    "value": -2,
    "left": {
        "value": -3,
        "left": null,
        "right": null
    },
    "right": {
        "value": 2,
        "left": null,
        "right": null
    }
} */


	

	vector<int> results2 = mostFrequentSum(&t1);
	Tree<int> t2(-2); 
	Tree<int> t2left(-3);
	Tree<int> t2right(2);
	t2.left = &t2left;
	t2.right = &t2right;
	
	total_sums.clear();
	vector<int> results = mostFrequentSum(&t2);
	
	return 0;
}