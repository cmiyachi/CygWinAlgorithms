#include <bits/stdc++.h>
using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    
    // use buf4 as a storage representing current buffer of read4 api output. it can store value from read4 call done during prev read api call or current read api. 
    // bufleft shows how much chars left to read in buf4.
    // ibuf is the current index from where you shall continue reading buf4.
    int bufleft = 0;
    char buf4[4] = "";
    int ibuf = 0;
    
public:
    
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int index = 0;
        while (n > 0) {
            if (bufleft > 0) {
                // if buf4 still has chars to be read.
                buf[index] = buf4[ibuf];
                index++; ibuf++; bufleft--;
                n--;
            } else {
                // else fill our buf4 temporary storage. 
                int tmp = read4(buf4);
                ibuf = 0;
                bufleft = tmp;
                if (bufleft <= 0) {
                    return index;
                }
            }    
        }
        return index;
    }
};

int main(void)
{
	Solution sol;
	
	
	return 0;
}