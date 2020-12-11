#include <bits/stdc++.h>
using namespace std;

class PrefixMapSum
{
public:
	unordered_map<string, int> str_map;
	
	
	void insert(string str, int val)
	{
		str_map[str] = val;
	}
	
	int sum(string prefix)
	{
		int result = 0;
		for (auto const& element: str_map)
		{
			string str = element.first; 
			if (str.rfind(prefix, 0) == 0) {
				result += str_map[str]; 
			}
		}
		return result; 
	}

};

int main(void)
{
	PrefixMapSum *mpsum = new PrefixMapSum();
	
	mpsum->insert("columnar",3);
	cout << mpsum->sum("col") << endl;
	mpsum->insert("column",2);
	cout << mpsum->sum("col") << endl;
}