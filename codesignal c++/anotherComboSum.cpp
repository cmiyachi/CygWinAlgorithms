#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int sum(vector<int> x) {
    int sum = 0;
    for (auto v : x) sum += v;
    return sum;
}

string cto_string(int i) {
    char buffer[20];
    sprintf(buffer, "%d", i);
    return string(buffer);
}

string ctoString(vector<int> v) {
	// if (v.size() == 0) return "Empty"; 
    string ret("(");
    int i = 0;
    for (; i < v.size()-1; ++i) ret += cto_string(v[i]) + " ";
    ret += cto_string(v[i]) + ")";
    return ret;
}

void Attempt(int i, const int& n, const vector<int>& arr, int firstJ, vector<int>& x, string& res) {
    int k = arr.size();
    for (int j = firstJ; j < k; ++j) {
        x[i] = arr[j];
        int sumX = sum(x);
        if (sumX == n) {
            res += ctoString(vector<int>(x.begin(), x.begin() + i + 1));
        }
        else if (sumX < n) {
            Attempt(i + 1, n, arr, j, x, res);
        }
        x[i] = 0;
        if (sumX > n) break;
    }
}

void preprocessRemoveDuplicateAndSort(vector<int>& a) {
    sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
}

std::string combinationSum(std::vector<int> a, int sum) {
    string ret = "";
    vector<int> x(sum);

    preprocessRemoveDuplicateAndSort(a);
    Attempt(0, sum, a, 0, x, ret);
    return ret != "" ? ret : "Empty";
}

int main() {
	vector<int> a = {5, 2, 2, 6};
    string s = combinationSum(a,3);
	
	cout << s << endl; 
    return 0;
}