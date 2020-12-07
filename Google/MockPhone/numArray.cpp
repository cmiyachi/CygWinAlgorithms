#include <vector>
using std::vector;

class NumArray {
public:
    NumArray(vector<int> nums) {
        m_cnt = nums.size();
        m_sum.resize(m_cnt * (m_cnt + 1) / 2);
        calcSums(nums);
    }
    
    int sumRange(int i, int j) {
        if (i > j) {
            return 0;
        }
        return m_sum[sumIndex(i, j)];
    }

    int sumIndex(int i, int j) {
        return i * m_cnt + j - i * (i + 1) / 2;
    }

    void calcSums(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i ++) {
            for (size_t j = i; j < nums.size(); j++) {
                if (i == j) {
                    m_sum[sumIndex(i, j)] = nums[j];
                } else {
                    m_sum[sumIndex(i, j)] = m_sum[sumIndex(i, j - 1)] + nums[j];
                }
            }
        }
    }
	
	
	
	class NumArray {
public:
    NumArray(vector<int>& nums) {
         m_cnt = nums.size();
        m_nums = nums; 
        m_sum.resize(m_cnt * (m_cnt + 1) / 2);
        calcSums(nums);
    }
    
    void update(int i, int val) {
        m_nums[i] = val;
        calcSums(m_nums);
    }
    
    int sumRange(int i, int j) {
         if (i > j) {
            return 0;
        }
        return m_sum[sumIndex(i, j)];   
        
    }
     int sumIndex(int i, int j) {
        return i * m_cnt + j - i * (i + 1) / 2;
    }
    
    void calcSums(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i ++) {
            for (size_t j = i; j < nums.size(); j++) {
                if (i == j) {
                    m_sum[sumIndex(i, j)] = nums[j];
                } else {
                    m_sum[sumIndex(i, j)] = m_sum[sumIndex(i, j - 1)] + nums[j];
                }
            }
        }
    }
    
public:
    size_t m_cnt;
    vector<int> m_sum;
    vector<int> m_nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

public:
    size_t m_cnt;
    vector<int> m_sum;
};

/*
Approach #1 (Brute Force) [Time Limit Exceeded]
Each time sumRange is called, we use a for loop to sum each individual element from index ii to jj.

private int[] data;

public NumArray(int[] nums) {
    data = nums;
}

public int sumRange(int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += data[k];
    }
    return sum;
}
Complexity analysis:

Time complexity : O(n)O(n) time per query. Each sumRange query takes O(n)O(n) time.

Space complexity : O(1)O(1). Note that data is a reference to nums and is not a copy of it.

Approach #2 (Caching) [Accepted]
Imagine that sumRange is called one thousand times with the exact same arguments. How could we speed that up?

We could trade in extra space for speed. By pre-computing all range sum possibilities and store its results in a hash table, we can speed up the query to constant time.

private Map<Pair<Integer, Integer>, Integer> map = new HashMap<>();

public NumArray(int[] nums) {
    for (int i = 0; i < nums.length; i++) {
        int sum = 0;
        for (int j = i; j < nums.length; j++) {
            sum += nums[j];
            map.put(Pair.create(i, j), sum);
        }
    }
}

public int sumRange(int i, int j) {
    return map.get(Pair.create(i, j));
}
Complexity analysis

Time complexity : O(1)O(1) time per query, O(n^2)O(n 
2
 ) time pre-computation. The pre-computation done in the constructor takes O(n^2)O(n 
2
 ) time. Each sumRange query's time complexity is O(1)O(1) as the hash table's look up operation is constant time.

Space complexity : O(n^2)O(n 
2
 ). The extra space required is O(n^2)O(n 
2
 ) as there are nn candidates for both ii and jj.

Approach #3 (Caching) [Accepted]
The above approach takes a lot of space, could we optimize it?

Imagine that we pre-compute the cummulative sum from index 00 to kk. Could we use this information to derive Sum(i, j)Sum(i,j)?

Let us define sum[k]sum[k] as the cumulative sum for nums[0 \cdots k-1]nums[0⋯k−1] (inclusive):

sum[k] = \left\{ \begin{array}{rl} \sum_{i=0}^{k-1}nums[i] & , k > 0 \\ 0 &, k = 0 \end{array} \right.sum[k]={ 
∑ 
i=0
k−1
​	
 nums[i]
0
​	
  
,k>0
,k=0
​	
 

Now, we can calculate sumRange as following:

sumRange(i, j) = sum[j + 1] - sum[i]sumRange(i,j)=sum[j+1]−sum[i]

private int[] sum;

public NumArray(int[] nums) {
    sum = new int[nums.length + 1];
    for (int i = 0; i < nums.length; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }
}

public int sumRange(int i, int j) {
    return sum[j + 1] - sum[i];
}
Notice in the code above we inserted a dummy 0 as the first element in the sum array. This trick saves us from an extra conditional check in sumRange function.

Complexity analysis

Time complexity : O(1)O(1) time per query, O(n)O(n) time pre-computation. Since the cumulative sum is cached, each sumRange query can be calculated in O(1)O(1) time.

Space complexity : O(n)O(n).

*/

class NumArray {
public:
    NumArray(vector<int> &nums) : psum(nums.size()+1, 0) {
        partial_sum( nums.begin(), nums.end(), psum.begin()+1);
    }

    int sumRange(int i, int j) {
        return psum[j+1] - psum[i];
    }
private:
    vector<int> psum;    
};