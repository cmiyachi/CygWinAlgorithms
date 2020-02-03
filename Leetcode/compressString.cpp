#include <bits/stdc++.h>
	
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) 
	{
		int anchor = 0, write = 0;
        for (int read = 0; read < chars.size(); read++) 
		{
            if (read + 1 == chars.size() || chars[read + 1] != chars[read]) 
			{
                chars[write++] = chars[anchor];
                if (read > anchor) 
				{
					int sub_size = read - anchor + 1; 
					string num_str = to_string(sub_size); 
					for (int i = 0; i < num_str.length();i++)
						chars[write++] = num_str[i]; 
                }
                anchor = read + 1;
            }
        }
        return write;
        
    }
};

int main(void)
{
	vector<char> input{'a','a','b','b','c','c','c'};
	Solution sol; 
	
	int result = sol.compress(input);
	for (int i = 0; i < result; i++)
		cout << input[i] << " , "; 
	
	cout << endl;
	
	vector<char> input3{'a','b','b','b','b','b','b','b','b','b','b','b','b'};
	result = sol.compress(input3); 
	for (int j = 0; j < result; j++)
		cout << input3[j] << " , "; 
	
	return 0;
}

