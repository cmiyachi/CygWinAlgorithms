#include <bits/stdc++.h>

using namespace std;

long prodByDays(vector<long> &machines, long days){
    long products(0);
    for(auto &machine: machines){
        products+=days/machine;
    }
    return products;
}

long minTime(vector<long> machines, long goal) {
    long days(0), total(0);
    sort(machines.begin(), machines.end());

    long minDays = 1;
    long maxDays = goal * machines.at(machines.size()-1);

    while(minDays<maxDays){
        days=(minDays+maxDays)/2;
        total=prodByDays(machines, days);

        if(total>=goal){
            maxDays=days;
        } else {
            minDays=days+1;
        }
    }

    return minDays;
}


int main(void)
{
	long goal = 5;
	vector<long> machines{2,3};
	
	cout << minTime(machines, goal); 
	return 0;
}