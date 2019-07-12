// C++ Program to find best buying and selling days 
#include <bits/stdc++.h> 
using namespace std; 




// solution structure 
class Interval { 
public: 
	int buy; 
	int sell; 
}; 

// This function finds the buy sell 
// schedule for maximum profit 
int stockBuySell(vector<int> price, int n) 
{ 
	int maxProfit = 0; 
	// Prices must be given for at least two days 
	if (n == 1) 
		return maxProfit; 

	int count = 0; // count of solution pairs 

	// solution vector 
	Interval sol[n / 2 + 1]; 

	// Traverse through given price array 
	int i = 0; 
	while (i < n - 1) { 
		// Find Local Minima. Note that the limit is (n-2) as we are 
		// comparing present element to the next element. 
		while ((i < n - 1) && (price[i + 1] <= price[i])) 
			i++; 

		// If we reached the end, break 
		// as no further solution possible 
		if (i == n - 1) 
			break; 

		// Store the index of minima 
		sol[count].buy = i++; 

		// Find Local Maxima. Note that the limit is (n-1) as we are 
		// comparing to previous element 
		while ((i < n) && (price[i] >= price[i - 1])) 
			i++; 

		// Store the index of maxima 
		sol[count].sell = i - 1; 

		// Increment count of buy/sell pairs 
		count++; 
	} 

	// print solution 
	if (count == 0) 
		return 0; 
	else { 
		for (int i = 0; i < count; i++)
		{
			int sell_day =sol[i].sell;
			int buy_day = sol[i].buy; 
			int temp = price[sell_day]-price[buy_day];  
			if (temp > maxProfit)
				maxProfit = temp;
		}			
	} 

	return maxProfit; 
} 
/* public class Solution {
    public int maxProfit(int prices[]) {
        int minprice = Integer.MAX_VALUE;
        int maxprofit = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
} */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int minprice = INT_MAX;
		int maxprofit = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			if (prices[i] < minprice)
				minprice = prices[i];
			else if ((prices[i] - minprice) > maxprofit)
				maxprofit = prices[i] - minprice; 
		}
		return maxprofit; 
    }
};

// Driver code 
int main() 
{ 
	// stock prices on consecutive days 
	vector<int> price{7,1,5,3,6,4};// 100, 180, 260, 310, 40, 535, 695 }; 
	int n = price.size();  

	Solution sol;
	
	cout << sol.maxProfit(price); 
	// fucntion call 
	//stockBuySell(price, n); 

	return 0; 
} 

// This is code is contributed by rathbhupendra 
