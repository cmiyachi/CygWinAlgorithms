class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Sort the given array 
    sort(nums.begin(), nums.end()); 
  
    // Return k'th element in the sorted array 
    return nums[nums.size() - k];
        
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end()); /// min O(N) ,vector<int>> greater<int> 

       /// pop k elements
       for(int i=1;i< k;i++){
        // cout<<pq.top()<<" ";
        pq.pop();
       }
        return pq.top(); 
    }
};

lass Solution {
public:
    int findKthLargest(vector<int>& n, int k) {
        nth_element(n.begin()+0, n.begin()+n.size()-k, n.end());
        return n[n.size()-k];
    }
};


class Solution {
public:

void heapify(int min_heap[], int curr_size, int index) {
    int left = (2 * index <= curr_size) ? (2 * index) : -1;
    int right = (2 * index + 1 <= curr_size) ? (2 * index + 1) : -1;
    
    int swap_index = index;
    if(left != -1 && min_heap[swap_index] > min_heap[left])
        swap_index = left;
    if(right != -1 && min_heap[swap_index] > min_heap[right])
        swap_index = right;
    
    if(swap_index != index) {
        swap(min_heap[swap_index], min_heap[index]);
        heapify(min_heap, curr_size, swap_index);
    }
}

void insert(int min_heap[], int *curr_size, int num) {
    *curr_size = *curr_size + 1;
    min_heap[*curr_size] = num;
    
    int curr_index = *curr_size;
    while(curr_index / 2 != 0 && min_heap[curr_index / 2] > min_heap[curr_index]) {
        swap(min_heap[curr_index / 2], min_heap[curr_index]);
        curr_index /= 2;
    }
}

void pop(int min_heap[], int *curr_size) {
    if(*curr_size == 0) return;
    
    swap(min_heap[1], min_heap[*curr_size]);
    *curr_size = *curr_size - 1;
    heapify(min_heap, *curr_size, 1);
}

int findKthLargest(vector<int>& nums, int k) {        
    int heap_size = 0;
    int min_heap[k + 1];
    
    for(int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if(!heap_size || heap_size < k) {
            insert(min_heap, &heap_size, num);
        } else if(heap_size == k && min_heap[1] < num) {
            pop(min_heap, &heap_size);
            insert(min_heap, &heap_size, num);
        }
    }
    
    return min_heap[1];
}
};