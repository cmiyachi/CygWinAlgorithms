#include <bits/stdc++.h> 
using namespace std; 

void mergeArrays(std::vector<int> &sequence, int left, int middle, int right) {
  std::vector<int> result;
  int i, j;

  for (i = left, j = middle; i < middle && j < right; ) {
    if (sequence[i] < sequence[j]) {
      result.push_back(sequence[i]);
      i++;
    }
    else {
      result.push_back(sequence[j]);
      j++;
    }
  }

  while (i < middle) {
    result.push_back(sequence[i]);
    i++;
  }

  while (j < right) {
    result.push_back(sequence[j]);
    j++;
  }

  for (i = left; i < right; i++) {
    sequence[i] = result[i - left];
  }
}

void split(std::vector<int> &sequence, int left, int right) {
	
	cout <<  left << " " << right << endl; 
	//if (left < right) 
	if (left - (right - 1) >= 0) return;
	
	  int middle = (left + right) / 2;
	  split(sequence, left, middle);
	  split(sequence, middle, right);
	  mergeArrays(sequence, left, middle, right);
	  
}

std::vector<int> mergeSort(std::vector<int> sequence) {

  split(sequence, 0, sequence.size());

  return sequence;
}

int main(void)
{
	vector<int> array{3, 6, 1, 5, 3, 6};
	
	vector<int> result = mergeSort(array); 
	
	for (int i = 0; i < result.size(); i++)
		cout <<  result[i] << " ";
	
	
	return 0;
}
