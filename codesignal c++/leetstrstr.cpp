#include <bits/stdc++.h>
using namespace std;


int compare(string haystack, string needle, int* kmp) {
   int index = -1;
   int i = 0, j = 0;
   while(i < haystack.length() && j < needle.length()) {
      if(haystack[i] == needle[j]) {
         if(index == -1)
            index = i;
         i++; j++;
      } else {
         if(j != 0) {            
            j = kmp[j - 1];            
            index = i - j;
         } else {
            i++;
            index = -1;
         }
      }
   }
   if(j != needle.length()) {
      index = -1;
   }
   return index;
}

void lps(string needle, int *kmp) {   
   int i = 0, j = 1;
   while(j < needle.length()) {
      if(needle[i] == needle[j]) {
         kmp[j] = i + 1;
         i++; j++;
      } else {
         if(i != 0) {
            i = kmp[i - 1];
         } else {
            kmp[j] = 0;
            j++;
         }
      }
   }
}

 
int strstr(string haystack, string needle)  {
	
	  if(needle.empty()) return 0;
   if(haystack.empty()) return -1;
   if(haystack.length() < needle.length()) return -1;
   int m = needle.length();
   int kmp[m];
   kmp[0] = 0;
   lps(needle, kmp);
   return compare(haystack, needle, kmp);
		
}

int main(void)
{
	string s1  = "This is www.firmcodes.com";
	string s2 = "firmcodes"			; 
   
   cout <<  strstr(s1, s2); 
 
	return 0;
}