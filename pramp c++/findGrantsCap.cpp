#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

double findGrantsCap( vector<int> grantsArray, int newBudget ) 
{
  // sort grants array
  sort(grantsArray.begin(), grantsArray.end()); 
  
  double cap = newBudget/ grantsArray.size(); 

  // iterate through the grans array
  for (int i = 0; i < grantsArray.size(); i++)
  {
    if (grantsArray[i] <= cap)
    {
      cap +=(double) (cap - grantsArray[i]) / (grantsArray.size() -1 - i); 
    }
    else
    {
      break;
    }
  } // for loop
  
  return cap; 
}

int main() {
  vector<int> grantsArray{2, 100, 50, 120, 1000}; 
  int newBudget = 190;
  
  double cap = findGrantsCap(grantsArray, newBudget);
  
  cout << cap; 
  return 0;
}

/*
#include <iostream>
#include <vector>

using namespace std;

double findGrantsCap( vector<int> grantsArray, int newBudget ) 
{
  sort(grantsArray.begin(), grantsArray.end());
  int n = grantsArray.size();
  for(int i=0; i<n; i++) {
    if(grantsArray[i] * (n-i) < newBudget)
      newBudget -= grantsArray[i];
    else
      return ((double)newBudget)/((double)(n-i));
  }
  return 0;
}

int main() {
  return 0;
}
*/