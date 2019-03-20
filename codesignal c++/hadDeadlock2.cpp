#include <set>
#include <vector>
#include <iostream>
using namespace std;

struct Visitor
{
    Visitor(std::vector<std::vector<int>>& _c):c(_c){}

    std::vector<std::vector<int>> c;
    set<int> visited;

    bool visit(int i);
};

bool hasDeadlock(std::vector<std::vector<int>> c)
{
  cout << "test ";
  Visitor v(c);
  for(int i = 0; i < c.size(); ++i)
  {
     if (v.visit(i) == true)
       return true;
  }
}

bool Visitor::visit(int i)
{
  if (visited.find(i) != visited.end())
    return true;

  visited.insert(i);

  for (int j: c[i])
  {
    if (visit(j) ==true)
      return true;
	}

  visited.erase(i);
  return false;
}

int main(void)
{
    std::vector<std::vector<int>> v = {{1,2,3},
                                       {2,3},
                                       {3},
                                       {}};
    hasDeadlock(v) ? cout << "True" : cout << "False";
}