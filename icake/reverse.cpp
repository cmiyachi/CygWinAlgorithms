#include <bits/stdc++.h>
using namespace std;
 void reverse(string& str); 
 
  void reverse(string& str)
{
    if (str.empty()) {
        return;
    }

    size_t leftIndex = 0;
    size_t rightIndex = str.length() - 1;

    while (leftIndex < rightIndex) {
        // swap characters
        swap(str[leftIndex], str[rightIndex]);

        // move towards middle
        ++leftIndex;
        --rightIndex;
    }
}

int main(void)
{
	string me = "Chris"; 
	reverse(me); 
	cout << me; 
	return 0;
}