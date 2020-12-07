/*
Overview
If we add one statement in the problem description that one could use the utility function in their preferred programming language to generate all permutations from a given list, i.e. itertools.permutations(list) in Python, then many of you would agree that this is definitely an easy problem.

Indeed, if we have all the permutations from the given list of digits, we could simply enumerate each of the permutations to see if we could build a valid time.

At the end of the enumeration, it would be easy to get the maximum of all valid times.

In the following sections, we would first present a solution with the built-in permutation utility.

Then, in case the interviewer insists that one should not use the permutation utility, we would present another solution where we hand-craft the permutations via enumeration.

At the end, we would also present a more generic and efficient algorithm to generate permutations via backtracking.

Approach 1: Enumerate the Permutations
Intuition

As we stated before, once we have the permutations at our disposal, the idea is simple: we iterate through all possible permutations of the given 4 digits, and for each permutation, we check if we could build a time out of it in the 24H format (i.e. HH:MM).

There are two conditions that we should meet, in order to construct a valid time format:

HH < 24: The first two digits, i.e. the hour, should be less than 24.

MM < 60: The last two digits, i.e. the minute, should be less than 60.

Algorithm

The algorithm can be implemented in a single loop over all the possible permutations for the given 4 digits.

At each iteration, we check if we could build a valid time based on the conditions we presented before.

Meanwhile, we use a variable (i.e.max_time) to keep track of the maximum valid time that we've seen during the iteration.
*/

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {

        int max_time = -1;
        // prepare for the generation of permutations next.
        std::sort(A.begin(), A.end());

        do {
            int hour = A[0] * 10 + A[1];
            int minute = A[2] * 10 + A[3];

            if (hour < 24 && minute < 60) {
                int new_time = hour * 60 + minute;
                max_time = new_time > max_time ? new_time : max_time;
            }
        } while(next_permutation(A.begin(), A.end()));

        if (max_time == -1) {
            return "";
        } else {
            std::ostringstream strstream;
            strstream << std::setw(2) << std::setfill('0') << max_time / 60
               << ":" << std::setw(2) << std::setfill('0') << max_time % 60;
            return strstream.str();
        }
    }
};

/*
Both the itertools.permutations API in Python and the next_permutation() in C++ can generate the permutations in lexicographic ordering. As a result, one can order the input array in descending order, rather than iterating all possible permutations, one can have an early stop as soon as we find the first valid time, which would also be the largest one, since the permutations are generated in lexicographic ordering.

Complexity Analysis

Time Complexity: \mathcal{O}(1)O(1)

For an array of length NN, the number of permutations would be N!N!. In our case, the input is an array of 4 digits. Hence, the number of permutations would be 4! = 4 * 3 * 2 * 1 = 244!=4∗3∗2∗1=24.

Since the length of the input array is fixed, it would take the same constant time to generate its permutations, regardless the content of the array. Therefore, the time complexity to generate the permutations would be \mathcal{O}(1)O(1).

In the above program, each iteration takes a constant time to process. Since the total number of permutations is fixed (constant), the time complexity of the loop in the algorithm is constant as well, i.e. 24 \cdot \mathcal{O}(1) = \mathcal{O}(1)24⋅O(1)=O(1).

To sum up, the overall time complexity of the algorithm would be \mathcal{O}(1) + \mathcal{O}(1) = \mathcal{O}(1)O(1)+O(1)=O(1).

Space Complexity: \mathcal{O}(1)O(1)

In the algorithm, we keep the permutations for the input digits, which are in total 24, i.e. a constant number regardless the input.

*/

/*

Approach 2: Permutation via Enumeration
Intuition

We are asked to generate permutations of four digits, i.e. D_1D_2D_3D_4D 
1
​	
 D 
2
​	
 D 
3
​	
 D 
4
​	
  from a given array e.g. A=[1, 2, 3, 4].

Each of the digit in the permutation, say D_1D 
1
​	
 , can come from any of the elements in the input array, e.g. D_1 = 1D 
1
​	
 =1 or D_1 = 2D 
1
​	
 =2 etc.

An intuitive idea would be that we can run nested loops to generate combination of digits, one loop per digit. At the end of loops, we filter out those invalid combinations, i.e. combinations that contains duplicate elements from the input array. The remaining combinations are actually permutations by definition.

Algorithm

Normally, we should have 4 nested loops, one loop per digit. But once we choose 3 non-duplicate elements from the input array, the last digit of the permutation is then fixed. As a result, we could reduce the loops down to 3-level nested loops, rather than 4.

At the end of loops, we check if we could build a valid time out of the permutation we generate.

Meanwhile, we use a variable (i.e.max_time) to keep track of the maximum valid time that we've seen during the iteration.

class Solution {
    private int max_time = -1;

    public String largestTimeFromDigits(int[] A) {
        this.max_time = -1;

        for (int i1 = 0; i1 < A.length; ++i1)
            for (int i2 = 0; i2 < A.length; ++i2)
                for (int i3 = 0; i3 < A.length; ++i3) {
                    // skip duplicate elements
                    if (i1 == i2 || i2 == i3 || i1 == i3)
                        continue;
                    // the total sum of indices is 0 + 1 + 2 + 3 = 6.
                    int i4 = 6 - i1 - i2 - i3;
                    int [] perm = {A[i1], A[i2], A[i3], A[i4]};
                    // check if the permutation can form a time
                    validateTime(perm);
                }
        if (this.max_time == -1)
            return "";
        else
            return String.format("%02d:%02d", max_time / 60, max_time % 60);
    }

    protected void validateTime(int[] perm) {
        int hour = perm[0] * 10 + perm[1];
        int minute = perm[2] * 10 + perm[3];
        if (hour < 24 && minute < 60)
            this.max_time = Math.max(this.max_time, hour*60 + minute);
    }
} 
Complexity Analysis

Time Complexity: \mathcal{O}(1)O(1)

We have a 3-level nested loops, each loop would have 4 iterations. As a result, the total number of iterations is 4 * 4 * 4 = 644∗4∗4=64.

Since the length of the input array is fixed, it would take the same constant time to generate its permutations, regardless the content of the array. Therefore, the time complexity to generate the permutations would be \mathcal{O}(1)O(1).

Note that the total number of permutations is 4! = 4 * 3 * 2 * 1 = 244!=4∗3∗2∗1=24. Yet, it takes us 64 iterations to generate the permutations, which is not the most efficient algorithm as one can see. As the size of array grows, this discrepancy would grow exponentially.

Space Complexity: \mathcal{O}(1)O(1)

In the algorithm, we keep a variable to keep track of the maximum time, as well as some intermediates variables for the function. Since the size of the input array is fixed, the total size of the local variables are bounded as well.
*/

/*
Approach 3: Permutation via Backtracking
Intuition

As we discussed before, the hard part of the problem is not enumerating over the permutations, but actually constructing the permutations itself. For practice, one can implement the permutation algorithms on these two problem: permutations and next permutation.

In the previous approach, we've presented a naive way to implement the permutation, which is not the most efficient algorithm obviously.

There have been several classic algorithms to generate the permutations. For instance, B.R. Heap proposed an algorithm (named Heap's algorithm) in 1963, which minimizes the movements of elements. It was still considered as the most efficient algorithm later in 1977.

Here we present an algorithm, which might not be the most efficient one but arguably more intuitive.

It is based on the ideas of divide-and-conquer, swapping and backtracking.

First of all, the algorithm follows the paradigm of divide and conquer. Given an array A[0:n], once we fix on the arrangements of the prefix subarray A[0:i], we then reduce the problem down to a subproblem, i.e. generating the permutations for the postfix subarray A[i:n].

In order to fix on a prefix subarray, we apply the operation of swapping, where we swap the elements between a fixed position and an alternative position.

divide and conquer

Finally, once we explore the permutations after a swapping operation, we then revert the choice (i.e. backtracking) by performing the same swapping, so that we could have a clean slate to start all over again.
backtracking

Algorithm

Now we can put together all the ideas that we presented before, and implement the permutation algorithm.

Here we implement the permutation algorithm as the function permutate(array, start) which generates the permutations for the postfix subarray of array[start:len(array)]. Once we implement the function, we invocate it as permutate(array, 0) to generate all the permutations from the array.

As a preview, once implemented, the function will unfold itself as in the following example.

DFS

For instance, starting from the root node, first we try to fix on the first element in the final combination, which we try to switch the element between the first position in the array and each of the positions in the array. Since there are 3 possible candidates, we branch out in 3 directions from the root node.

The function can be implemented in recursion, due to its nature of divide-and-conquer and backtracking.

The base case of the function would be start == len(array), where we've fixed all the prefixes and reached the end of the combination. In this case, we simply add the current array as one of the results of combination.

When we still have some postfix that need to be permutated, i.e. start < len(array), we then apply backtracking to try out all possible permutations for the postfixes, i.e. permutate(array, start+1). More importantly, we need to swap the start element with each of the elements following the start index (including the start element). The goal is two-fold: 1). we generate different prefixes for the final combination; 2). we generate different lists of candidates in the postfixes, so that the permutations generated from the postfixes would vary as well.

At the end of backtracking, we will swap the start element back to its original position, so that we can try out other alternatives.

For each permutation, we apply the same logic as in the previous approach, i.e. check if the permutation is of valid time and update the maximum time.

class Solution {
    private int max_time = -1;

    public String largestTimeFromDigits(int[] A) {
        this.max_time = -1;
        permutate(A, 0);
        if (this.max_time == -1)
            return "";
        else
            return String.format("%02d:%02d", max_time / 60, max_time % 60);
    }

    protected void permutate(int[] array, int start) {
        if (start == array.length) {
            this.build_time(array);
            return;
        }
        for (int i = start; i < array.length; ++i) {
            this.swap(array, i, start);
            this.permutate(array, start + 1);
            this.swap(array, i, start);
        }
    }

    protected void build_time(int[] perm) {
        int hour = perm[0] * 10 + perm[1];
        int minute = perm[2] * 10 + perm[3];
        if (hour < 24 && minute < 60)
            this.max_time = Math.max(this.max_time, hour * 60 + minute);
    }

    protected void swap(int[] array, int i, int j) {
        if (i != j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}

There are too many corner cases, so it's easier to just brute-force all 24 combinations and find the maximum over valid ones.

Thanks to @AdamTai for pointing out that, since we permutating from smallest to largest, the last valid combination is also the largest one. Therefore, we can sort the input descending, iterate from largest to smallest using prev_permutation and return the first valid time.

string largestTimeFromDigits(vector<int>& A) {
  sort(begin(A), end(A), greater<int>());
  do if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6) 
      return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
  while (prev_permutation(begin(A), end(A)));
  return "";
}

*/

class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        
    }
};