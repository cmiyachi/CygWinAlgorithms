#include <bits/stdc++.h>
using namespace std;


vector<long long> regular_numbers(long long n)
{
	vector<long long> twos, threes, fives;
	for (long long i = 0; i < n; i++)
	{
		twos.push_back(pow(2,i));
		threes.push_back(pow(3,i));
		fives.push_back(pow(5,i));
	}
	
	long long k = 0;
	set<long long> result;
	for (long long t : twos)
		for (long long th: threes)
			for (long long f :fives)
			{
				result.insert(t*th*f);
			}
		
	
	vector<long long> final(result.begin(), result.end());
	sort(final.begin(), final.end());
	
	vector<long long> ffinal(final.begin(), final.begin()+n); 
	
	return ffinal; 
}


// Syntax to create a min heap for priority queue 

vector<long long> regular_numbers2(long long n)
{
	vector<long long> results;
	long long sol = 1; 
	int last = 0, count = 0;
	priority_queue <long long, vector<long long>, greater<long long>> gq;  
	
	gq.push(sol); 
	
	while (count < n)
	{
		long long x = gq.top(); gq.pop();
		if (x > last)
		{
			results.push_back(x);
			last = x; count++;
			gq.push(2*x);
			gq.push(3*x);
			gq.push(5*x);
		}
	}
	
	return results;
}

int main(void)
{
	
	long long n = 12;
	vector<long long> result = regular_numbers(n);
	
	for (long long x : result)
		cout << x << " "; 
	
	vector<long long> result2 = regular_numbers2(n);
	
	for (long long x : result2)
		cout << x << " "; 
	return 0;
}
	