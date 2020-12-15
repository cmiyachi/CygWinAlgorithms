#include <bits/stdc++.h> 
using namespace std; 


class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        int k = costs[0].size();
        int n = costs.size();

        for (int house = 1; house < n; house++) {
            for (int color = 0; color < k; color++) {
                int minval = INT_MAX;
                for (int previousColor = 0; previousColor < k; previousColor++) {
                    if (color == previousColor) continue;
                    minval = min(minval, costs[house - 1][previousColor]);
                }
                costs[house][color] += minval;
            }
        }

        // Find the minimum in the last row.
        int minval = INT_MAX;
        for (int c : costs[n - 1]) {
            minval = min(minval, c);
        }
        return minval;
    }
};
/*
Intuition

Let's look at a bigger example now, and view the problem in a different way to how we did before. For this example, k = 6 and n = 5.

[[10, 6, 16, 25, 7, 28], [7, 16, 18, 30, 16, 25], [8, 26, 6, 22, 26, 19], [10, 23, 14, 17, 23, 9], [12, 14, 27, 7, 8, 9]]

And here is a diagram of the input grid.

A picture of the input grid.

Each row represents the different colors a house could be. Remember that the colors are represented by numbers. The actual colors are only to make the table easier to read.

The problem we're trying to solve is equivalent to the following: pick exactly one number from each row such that the sum of those numbers is minimized. Because 2 adjacent houses cannot be the same color, adjacent rows must be picked from different columns. This is a straightforward variant of one of those "classic" minimum-path-in-a-grid dynamic programming problems.

The way that we solve it is to iterate over the cells and determine what the cheapest way of getting to that cell is. We'll work from top to bottom.

To begin with, we say the first row (house 0) is already completed. We don't need to make any changes to it.

Then, for each cell in the second row, we work out the cheapest way of getting to it from the first row is. For example, to get to [1][red] we have to go through any of the non-red cells from the row above. We want to go through the minimum.

Choosing the best path to house 1, red.

We show our decision by updating [1][red] to 7 + 6 = 13.

We can repeat this for the rest of the second row, and then work down each of the remaining rows.

Here's an animation of the algorithm being carried out.

When we're finished, the final answer is the minimum value in the last row.

Algorithm

We'll do this in the same way we did in the animation above—an in-place algorithm that over-writes the input grid.
*/