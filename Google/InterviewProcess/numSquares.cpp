/*Approach 1: Brute-force Enumeration [Time Limit Exceeded]
Intuition

The problem asks us to find the least numbers of square numbers that can sum up to a given number. We could rephrase the problem as follows:

Given a list of square numbers and a positive integer number n, one is asked to find a combination of square numbers that sum up to n, and the combination should contain the least numbers among all possible solutions.
Note: one could reuse the square numbers in the combination.

From the above narrative of the problem, it seems to be a combination problem, to which an intuitive solution would be the brute-force enumeration where we enumerate all possible combinations and find the minimal one of them.

We could formulate the problem in the following formula:

\text{numSquares}(n) = \min \Big(\text{numSquares(n-k) + 1}\Big) \qquad \forall k \in \{\text{square numbers}\}numSquares(n)=min(numSquares(n-k) + 1)∀k∈{square numbers}

From the above formula, one can translate it into a recursive solution literally. Here is one example

class Solution(object):
    def numSquares(self, n):
        square_nums = [i**2 for i in range(1, int(math.sqrt(n))+1)]

        def minNumSquares(k):
            """ recursive solution """
            # bottom cases: find a square number
            if k in square_nums:
                return 1
            min_num = float('inf')

            # Find the minimal value among all possible solutions
            for square in square_nums:
                if k < square:
                    break
                new_num = minNumSquares(k-square) + 1
                min_num = min(min_num, new_num)
            return min_num

        return minNumSquares(n)
		
		he above solution could work for small numbers. However, as one would find out, we would quickly run into the Time Limit Exceeded exception even for medium-size numbers (e.g. 55).

Or simply we might encounter the Stack Overflow due the to the excessive recursion.


Approach 2: Dynamic Programming
Intuition

The reason why it failed with the brute-force approach is simply because we re-calculate the sub-solutions over and over again. However, the formula that we derived before is still valuable. All we need is a better way to implement the formula.

\text{numSquares}(n) = \min \Big(\text{numSquares(n-k) + 1}\Big) \qquad \forall k \in \{\text{square numbers}\}numSquares(n)=min(numSquares(n-k) + 1)∀k∈{square numbers}

One might notice that, the problem is similar to the Fibonacci number problem, judging from the formula. And like Fibonacci number, we have several more efficient ways to calculate the solution, other than the simple recursion.

One of the ideas to solve the stack overflow issue in recursion is to apply the Dynamic Programming (DP) technique, which is built upon the idea of reusing the results of intermediate sub-solutions to calculate the final solution.

To calculate the value of \text{numSquares}(n)numSquares(n), first we need to calculate all the values before nn, i.e. \text{numSquares}(n-k) \qquad \forall{k} \in\{\text{square numbers}\}numSquares(n−k)∀k∈{square numbers}. If we have already kept the solution for the number n-kn−k in somewhere, we then would not need to resort to the recursive calculation which prevents the stack overflow.

Algorithm

Based on the above intuition, we could implement the DP solution in the following steps.

As for almost all DP solutions, we first create an array dp of one or multiple dimensions to hold the values of intermediate sub-solutions, as well as the final solution which is usually the last element in the array. Note that, we create a fictional element dp[0]=0 to simplify the logic, which helps in the case that the remainder (n-k) happens to be a square number.
As an additional preparation step, we pre-calculate a list of square numbers (i.e. square_nums) that is less than the given number n.
As the main step, we then loop from the number 1 to n, to calculate the solution for each number i (i.e. numSquares(i)). At each iteration, we keep the result of numSquares(i) in dp[i], while resuing the previous results stored in the array.
At the end of the loop, we then return the last element in the array as the result of the solution.
In the graph below, we illustrate how to calculate the results of numSquares(4) and numSquares(5) which correspond to the values in dp[4] and dp[5].

class Solution {

  public int numSquares(int n) {
    int dp[] = new int[n + 1];
    Arrays.fill(dp, Integer.MAX_VALUE);
    // bottom case
    dp[0] = 0;

    // pre-calculate the square numbers.
    int max_square_index = (int) Math.sqrt(n) + 1;
    int square_nums[] = new int[max_square_index];
    for (int i = 1; i < max_square_index; ++i) {
      square_nums[i] = i * i;
    }

    for (int i = 1; i <= n; ++i) {
      for (int s = 1; s < max_square_index; ++s) {
        if (i < square_nums[s])
          break;
        dp[i] = Math.min(dp[i], dp[i - square_nums[s]] + 1);
      }
    }
    return dp[n];
  }
}With this trick of reformulation, we could dramatically reduce the risk of stack overflow.

Algorithm

First of all, we prepare a list of square numbers (named square_nums) that are less than the given number n.
In the main loop, iterating the size of combination (named count) from one to n, we check if the number n can be divided by the sum of the combination, i.e. is_divided_by(n, count).
The function is_divided_by(n, count) can be implemented in the form of recursion as we defined in the intuition section.
In the bottom case, we have count==1, we just need to check if the number n is a square number itself. We could use the inclusion test with the list square_nums that we prepared before, i.e. n \in \text{square\_nums}n∈square_nums. And if we use the set data structure for square_nums, we could obtain a faster running time than the approach of n == int(sqrt(n)) ^ 2.
Concerning the correctness of the algorithm, often the case we could prove the Greedy algorithm by contradiction. This is no exception. Suppose we find a count=m that can divide the number n, and suppose in the later iterations there exists another number count=p that can also divide the number and the combination is smaller than the found one i.e. p < m. Given the order of the iteration, the count=p would have been discovered before count=m which is contradict to the fact that p comes later than m. Therefore, we can say that the algorithm works as expected, which always finds the minimal size of combination.

Here are some sample implementation. In particular, the Python solution took ~70ms, which was faster than ~ 90% submissions at the time.



class Solution {
  Set<Integer> square_nums = new HashSet<Integer>();

  protected boolean is_divided_by(int n, int count) {
    if (count == 1) {
      return square_nums.contains(n);
    }

    for (Integer square : square_nums) {
      if (is_divided_by(n - square, count - 1)) {
        return true;
      }
    }
    return false;
  }

  public int numSquares(int n) {
    this.square_nums.clear();

    for (int i = 1; i * i <= n; ++i) {
      this.square_nums.add(i * i);
    }

    int count = 1;
    for (; count <= n; ++count) {
      if (is_divided_by(n, count))
        return count;
    }
    return count;
  }
}Algorithm

One can literally follow the above cases to implement the solution.

First, we check if the number n is of the form n = 4^{k}(8m+7)n=4 
k
 (8m+7), if so we return 4 directly.
Otherwise, we further check if the number is of a square number itself or the number can be decomposed the sum of two squares.
In the bottom case, the number can be decomposed into the sum of 3 squares, though we can also consider it decomposable by 4 squares by adding zero according to the four-square theorem. But we are asked to find the least number of squares.
We give some sample implementations here. The solution is inspired from the posts of TCarmic and StefanPochmann in the Discussion forum.



class Solution {

  protected boolean isSquare(int n) {
    int sq = (int) Math.sqrt(n);
    return n == sq * sq;
  }

  public int numSquares(int n) {
    // four-square and three-square theorems.
    while (n % 4 == 0)
      n /= 4;
    if (n % 8 == 7)
      return 4;

    if (this.isSquare(n))
      return 1;
    // enumeration to check if the number can be decomposed into sum of two squares.
    for (int i = 1; i * i <= n; ++i) {
      if (this.isSquare(n - i * i))
        return 2;
    }
    // bottom case of three-square theorem.
    return 3;
  }
}*/

int numSquares(int n) {
    static vector<int> dp {0};
    while (dp.size() <= n) {
        int m = dp.size(), squares = INT_MAX;
        for (int i=1; i*i<=m; ++i)
            squares = min(squares, dp[m-i*i] + 1);
        dp.push_back(squares);
    }
    return dp[n];
}
class Solution {  
public:  
    int is_square(int n){  
        int temp = (int) sqrt(n);  
        return temp * temp == n;  
    }  
    int numSquares(int n) {  
        while ((n & 3) == 0) //n%4 == 0  
            n >>= 2;  
        if ((n & 7) == 7) return 4; //n % 8 == 7  
        if(is_square(n)) return 1;  
        int sqrt_n = (int) sqrt(n);  
        for(int i = 1; i<= sqrt_n; i++){  
            if (is_square(n-i*i)) return 2;  
        }  
        return 3;  
    }  
};/*
UPDATE: in order to understand, I suggest u read:

here is the Lagrange's Four Square theorem - Limit the result to <= 4:
https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem

And this article, in which you can also find the way to present a number as a sum of four squares:
http://www.alpertron.com.ar/4SQUARES.HTM*/