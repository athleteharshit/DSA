#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void selectionSortO(vector<int> &arr) {
  int n = arr.size();
  for(int i = 0; i < n; i++) {
    int minIndex = i;
    for(int j = i + 1; j < n; j++) {
      if(arr[minIndex] > arr[j]) {
        minIndex = j;
      }
    }
    if(minIndex != i) {
      swap(arr[minIndex], arr[i]);
    }
  }
}

// my way
void selectionSort(vector<int> &arr) {
  int n = arr.size();
  for(int i = 0; i < n; i++) {
    for(int j = n - 1; j >= i; j--) {
        if(arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j-1]);
        }
    }
  }
}

int main() {
  vector<int> arr = {44, 33, 55, 22, 11};
  // bubbleSort(arr);
// selectionSort(arr);
selectionSortO(arr);

  for (auto i : arr) {
    cout << i << endl;
  }
  return 0;
}