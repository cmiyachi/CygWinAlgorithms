#include<iostream>
using namespace std;

int countWays(int n){
   if(n==0 || n==1){
    return 1;
   }
   /*if(n==2){
    return 2;
   }
   */
   if(n<0){
    return 0;
   }
   return countWays(n-1) + countWays(n-2) + countWays(n-3);

}

class Solution {
public:
    int climbStairs(int n) {
    int f[n + 1];  
    int i; 
    if(n==1){
        return 1;
    }
    // 0th and 1st number of the  
    // series are 0 and 1 
    f[0] = 0; 
    f[1] = 1; 
    f[2] = 2;
    for(i = 3; i <= n; i++) 
    { 
          
       //Add the previous 2 numbers  
       // in the series and store it 
       f[i] = f[i - 1] + f[i - 2]; 
    } 
    return f[n]; 
        
    }
};

int main(){
  int n;
  cin>>n;
  cout<<countWays(n)<<endl;

  return 0;
}
