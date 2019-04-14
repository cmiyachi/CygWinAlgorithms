/*
You are the head zookeeper at a large zoo. You've been contacted by schools in the area that want to bring in classes so that students can feed the animals. The animals can only be fed once a day, so no two classes can come on the same day if they want to feed the same animals.

You have a list classes, such that classes[i] is a list of animals that the ith class wants to feed. Classes i and j cannot come on the same day if an animal in classes[i] also appears in classes[j] (for i ≠ j). Your job is to determine the minimum number of days you would need to have all the classes come to feed the animals if they can all come within 5 days. If it isn't possible for all the classes to come within 5 days, return -1 instead.

Example

For classes = [["Tiger", "Lima", "Frog"], ["Tiger", "Zebra","Lion"], ["Tiger", "Rabbit"], ["Emu", "Zebra", "Rabbit"]], the output should be
feedingTime(classes) = 3.
Classes 0, 1, and 2 all want to feed the Tiger, so they have to come on different days. Class 3 cannot come on the same day as class 1 (because of the Zebra) or class 2 (because of the Rabbit), but they can come on the same day as class 0. Therefore it only takes 3 days for all the classes to visit the zoo.

For classes = [["Tiger", "Lima", "Frog"], ["Tiger", "Zebra", "Lion"], ["Tiger", "Rabbit"], ["Lima", "Zebra", "Rabbit"]], the output should be
feedingTime(classes) = 4.
Each class has to come on a separate day, because every pair of classes has at least one animal in common.

For classes = [["Lion", "Emu"], ["Giraffe", "Peacock"], ["Lima"], ["Tiger", "Cheetah", "Slugs"], ["Snakes", "Sealion"]], the output should be
feedingTime(classes) = 1.
No classes have animals in common, so they can all come on the same day.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.array.string classes

classes[i] is a list of animals that the ith class wants to feed.

Guaranteed constraints:
1 ≤ classes.length ≤ 15,
1 ≤ classes[i].length ≤ 10,
1 ≤ classes[i][j].length ≤ 14.

[output] integer

The minimum number of days you would need to have all the classes come to feed the animals. If it isn't possible for all the classes to come within 5 days, return -1 instead.
*/

#include <iostream>
#include <vector>
#include <set> 
#include <bits/stdc++.h> 

using namespace std; 

vector<vector<int>>adj;
vector<int>color;
int totColors;
const int MAX_COLORS_ALLOWED = 5;

bool isSafe(int node,int colr){
  for(int i=0;i<adj[node].size();i++){
    if(color[adj[node][i]]==colr)return false;
  }
  return true;
}

bool colorGraphUtil(int node,int maxAllowedColors){
  if(node==adj.size())return true;
  for(int colr=1;colr<=maxAllowedColors;colr++){
    if(isSafe(node,colr)){
      color[node]=colr;
      bool check = colorGraphUtil(node+1,maxAllowedColors);
      if(check==false){
        color[node]=0;
      }else return true;
    }
  }
  return false;
}

bool colorGraph(int maxAllowedColors){
  int sz=adj.size();
  color=vector<int>(sz,0);
  if(colorGraphUtil(0,maxAllowedColors))return true;
  return false;
}

int feedingTime(std::vector<std::vector<std::string>> classes) {
    int sz=classes.size();
    adj=vector<vector<int>>(sz);
    for(int i=0;i<sz;i++){
      unordered_set<string> ustA;
      for(int j=0;j<classes[i].size();j++)ustA.insert(classes[i][j]);
      for(int j=i+1;j<sz;j++){
        for(int k=0;k<classes[j].size();k++){
          if(ustA.find(classes[j][k])!=ustA.end()){
            adj[i].push_back(j);
            adj[j].push_back(i);
          }
        }
      }
    }
    int ans=0;
    for(int i=1;i<=MAX_COLORS_ALLOWED;i++){
      if(colorGraph(i)){ans=i; break;}
    }
    
    if(ans==0)return -1;
    return ans;
}

int main()
{
	vector<vector<string>> classes = {{"Lion", "Emu"}, {"Giraffe", "Peacock"}, {"Lima"}, {"Tiger", "Cheetah", "Slugs"}, {"Snakes", "Sealion"}}; 
	
	cout << feedingTime(classes); 
	
	return 0;
	
}