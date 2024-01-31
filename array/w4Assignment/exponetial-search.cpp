#include<iostream>
#include<vector>
using namespace std;

// HW 03: Exponential Search (Concept)

/*
Exponential search involves two steps:  
Step 01: Find range where element is present
Step 02: Do Binary Search in above found range

Exponential search applications:
Search in ∞ infinite array (Sorted Array)
Better than binary search when target element is near in beginning

Time complexity: O(Log n)
Space complexity: O(1)
*/

// first approach apply linear search
int linearSearch(vector<int> arr, int target) {
    int i = 0;

    while(arr[i] <= target) {
        if(arr[i] == target) {
            return i;
        }
        i++;
    }

    return -1;
}

int bs(vector<int> arr, int target, int start, int end) {
  while (start <= end) {
    int mid = start + ((end - start) / 2);
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1;
}

// binary search
int expoSearch(vector<int> arr, int target) {
  int n = arr.size();
  if (n == 0)
    return 0;
  int i = 1;
  while (i < n && arr[i] <= target) {
    i = i * 2;
  }
  return bs(arr, target, i / 2, min(i, n - 1));
}

int main() {
    vector<int> arr = {1, 2, 4, 5, 6, 8, 12, 15, 19, 21, 34, 35, 89, 123};
    // cout << linearSearch(arr, 39) << endl;
    cout << expoSearch(arr, 39) << endl;

    return 0;
}