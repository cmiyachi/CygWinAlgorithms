#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

std::string swapLexOrder(std::string str, std::vector<std::vector<int>> pairs)
{
    if(pairs.size() == 0) return str;
    std::vector<std::set<int>> pairpool; //pairpool : contains sets of interchangeable indices
    std::vector<std::vector<std::string>> stringpool; //stringpool : contains vectors of interchangeable characters

    //creates pairpool structure
    for(std::size_t i = 0; i < pairs.size(); i++)
    {
        bool alrExists = false;
        std::set<int> newSet;
        for(auto& p : pairpool)
        {
            for(auto ele : p)
            {
                if((pairs[i][0] == ele) || (pairs[i][1] == ele))
                {
                    if(!alrExists)
                    {
                        alrExists = true;
                        p.insert(pairs[i][0]);
                        p.insert(pairs[i][1]);
                        newSet = p;
                    }
                    else
                    {
                        if(p == newSet) break;
                        p.insert(newSet.begin(), newSet.end());
                        pairpool.erase(std::remove(pairpool.begin(), pairpool.end(), newSet), pairpool.end());
                        break;  //  needed this break statement really badly
                    }
                }
            }
        }
        if(!alrExists)
        {
            newSet.insert(pairs[i][0]);
            newSet.insert(pairs[i][1]);
            pairpool.push_back(newSet);
        }
    }

    //creates sorted stringpool structure
    for(auto p : pairpool)
    {
        std::vector<std::string> newset;
        for(auto ele : p)
        {
            newset.push_back(str.substr(ele - 1, 1));
        }
        std::sort(newset.begin(), newset.end());
        stringpool.push_back(newset);
    }

    //uses stringpool and pairpool to modify string only one time through
    int counter = 0;
    for(auto p : pairpool)
    {
        for(auto ele : p)
        {
            str.replace(ele - 1, 1, stringpool[counter].back());
            stringpool[counter].pop_back();
        }
        counter++;
    }

    return str;
}

int main()
{
    std::cout << swapLexOrder("acxrabdz", {{1, 3}, {6, 8}, {3, 8}, {2, 7}}) << "\n";
    std::string STR = "lvvyfrbhgiyexoirhunnuejzhesylojwbyatfkrv";
    std::vector<std::vector<int>> PAIR =
    {
        {13, 23},
        {13, 28},
        {15, 20},
        {24, 29},
        {6, 7},
        {3, 4},
        {21, 30},
        {2, 13},
        {12, 15},
        {19, 23},
        {10, 19},
        {13, 14},
        {6, 16},
        {17, 25},
        {6, 21},
        {17, 26},
        {5, 6},
        {12, 24}
    };
    std::cout << swapLexOrder(STR, PAIR) << "\n";
    return 0;
}