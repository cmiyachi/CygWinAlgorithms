#include <iostream>
using namespace std;

int ap_term(int first, int second, int n);

int main() {
int numCases;
int first, second, n;
cin >> numCases;
for(int i = 0; i < numCases; i++){
cin >> first >> second;
cin >> n;
cout << ap_term(first, second, n) << endl;
}
return 0;
}

int ap_term(int first, int second, int n){
int d = second - first; // Common Difference
int nthTerm = first + (n - 1) * d;
return nthTerm;
}