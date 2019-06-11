#include <string>
 
#include <iostream>
#include <climits>

using namespace std;
class Solution
{
  public:
    int myAtoi(string str)
    {
        int i = 0, base = 0, sign = 1;
        while (str[i] == ' ')
        {
            i++;
        }

        if (str[i] == '+')
        {
            i++;
        }
        else if (str[i] == '-')
        {
            sign = -1;
            i++;
        }
        while (i<str.size() && isdigit(str[i]))
        {
            int num = int(str[i] - '0');
            if (INT_MAX / 10 < base)
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            if (INT_MAX / 10 == base)
            {
                if (num >= 7)
                {
                    if (sign == 1)
                    {
                        return INT_MAX;
                    }
                    else if (num == 7)
                    {
                        return INT_MIN + 1;
                    }
                    else
                        return INT_MIN;
                }
            }
            base = 10 * base + num;
            i++;
        }

        return sign * base;
    }
};

int main()
{
    Solution numString;
    // cout << "\nresult:" << numString.myAtoi("42");              // 42
    // cout << "\nresult:" << numString.myAtoi("   -42");          // -42
    // cout << "\nresult:" << numString.myAtoi("4193 with words"); //4193
    // cout << "\nresult:" << numString.myAtoi("words and 987");   //0
    // cout << "\nresult:" << numString.myAtoi("-91283472332");    // -2147483648
    // cout << "\nresult:" << numString.myAtoi("3.14159");         // 3
    // cout << "\nresult:" << numString.myAtoi("+1");              // 1
    // cout << "\nresult:" << numString.myAtoi("+-2");             // 0
    // cout << "\nresult:" << numString.myAtoi("  -0012a42"); // -12
    // cout << "\nresult:" << numString.myAtoi("   +0 123"); // 0
    cout << "\nresult:" << numString.myAtoi("-2147483647"); // -2147483647
    cout << "\nresult:" << numString.myAtoi("2147483648");  // 2147483647
    cout << "\nresult:" << numString.myAtoi("-2147483646"); // -2147483646

    getchar();
}