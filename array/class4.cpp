#include<iostream>
#include<vector>
using namespace std;

// Problem: sort -ve one side and +ve one side;
// i/p-> [10, -1, 12, -2, -4, 5, 9, -123]
// o/p-> [-1, -2, -4, -123, 10, 12, 5, 9]
void sortNegativeAndPostive(vector<int> &arr, int size) {
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] < 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

// Problem: Sort color (0, 1, 2);
// appr: 3 pointer app, left = 0, right = length -1, index for treverse
// left side fill 0 and right side fill 2
void sortColor(vector<int> &arr, int size) {
    int index = 0;
    int left = 0;
    int right = size - 1;

    while(index <= right) {
        if(arr[index] == 0) {
            swap(arr[index], arr[left]);
            index++;
            left++;
        }else if(arr[index] == 2) {
            swap(arr[index], arr[right]);
            right--;
            // catch -> no need to index++ because of i don't know kuch bhi ho sakta h 0, 1, 2
        }else {
            index++;
        }
    }
}

// Problem: rotate a array by k -> 189
// modules approach-> (index + k ) % size
void rotateArrayByK(vector<int> &arr, int size, int k) {
    vector<int> ans(size);

    for(int i = 0; i < size; i++) {
        int index = (i + k) % size;
        ans[index] = arr[i];
    }
    arr = ans;
}

// Problem: find missing number -> 268
// count all sum 0 to size and minus given array sum , then get answer
int missingNumber(vector<int> arr, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }

    int totalSum = (size * (size + 1))/2;
    return totalSum - sum;
}

int main() {
    // vector<int> arr = {10, -1, 12, -2, -4, 5, 9, -123};
    // int size = arr.size();
    // sortNegativeAndPostive(arr, size);
    // for(int i = 0; i < size; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // vector<int> arr = {0, 1, 2, 2, 1, 0, 0, 1, 2};
    // sortColor(arr, arr.size());
    // rotateArrayByK(arr, arr.size(), 3);
    // for(int i = 0; i < arr.size(); i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;


    vector<int> arr = {0, 1, 3, 4};
    
    cout << missingNumber(arr, arr.size()) << endl;
    return 0;
}