#include<iostream>
using namespace std;

void mergeArrays(int x[],int y[],int a[],int s,int e){


}

void mergeSort(int a[],int s,int e){
    if(s>=e){
        return;
    }
// option 1 - copy half elements in x and your

    
}

int main(){


  return 0;
}


#include <vector>
using namespace std;
void merge(vector<int>& nums, int l, int m, int r);
void mergeSortHelper(vector<int>& nums, int l, int r);

vector<int> mergeSort(vector<int> array) {
  // Write your code here.
	mergeSortHelper(array, 0, array.size()-1);
	
  return array; 
}

void mergeSortHelper(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int m = l + (r - l) / 2; //middle index, same as (l+r)/2
        mergeSortHelper(nums, l, m);
        mergeSortHelper(nums, m + 1, r);
        merge(nums, l, m, r);
    }
void merge(vector<int>& nums, int l, int m, int r){
        vector<int> tmp(r - l + 1);
        int i = l; // index for left subarray
        int j = m + 1; // index for right subarray
        int k = 0; // index for temporary array
        while(i <= m && j <= r){
            if(nums[i] <= nums[j]) tmp[k++] = nums[i++]; 
            else tmp[k++] = nums[j++];
        }
        while(i <= m) tmp[k++] = nums[i++];
        while(j <= r) tmp[k++] = nums[j++]; 
        for(i = 0; i < k; i++) nums[l + i] = tmp[i];
    }
/*
void merge(vector<int>& nums, int l, int m, int r){
        vector<int> tmp(r - l + 1);
        int i = l; // index for left subarray
        int j = m + 1; // index for right subarray
        int k = 0; // index for temporary array
        while(i <= m && j <= r){
            if(nums[i] <= nums[j]) tmp[k++] = nums[i++]; 
            else tmp[k++] = nums[j++];
        }
        while(i <= m) tmp[k++] = nums[i++];
        while(j <= r) tmp[k++] = nums[j++]; 
        for(i = 0; i < k; i++) nums[l + i] = tmp[i];
    }
	
	// mergeSort(nums, 0, nums.size() - 1);
    void mergeSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int m = l + (r - l) / 2; //middle index, same as (l+r)/2
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    } */
