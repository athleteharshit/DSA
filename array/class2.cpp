#include<iostream>
#include<vector>
using namespace std;

// Problem: find unique element
// by using XOR opretor xor, if you are applying xor on sum number return 0
// ex: 5 ^ 5 = 0
// a  b  ans
// 0  0   0
// 0  1   1
// 1  0   1
// 1  1   0
int uniqueEle(vector<int> arr) {
    int ans = 0;
    for(auto i: arr) {
        ans = ans ^ i;
    }
    return ans;
}

// Problem: Print all pairs
void printPair(vector<int> arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << arr[i] << " " << arr[j] << endl;
        }
    }
}

// Problem: Print all Triplets
void printTriplet(vector<int> arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
            }
        }
    }
}

// Problem: 0 and 1 sort
// two pointer approach 
// i = 0, j = 0, 
// set 0 in i postion and increment 
vector<int> zeroAndOne(vector<int> arr, int size) {
    int i = 0;
    int j = 0;

    while(j < size) {
        if(arr[j] == 0) {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }else {
            j++;
        }
    }
    return arr;
}

// Problem: Shift by 1 element in array
//  always shift from backside the array, ex ->i = size -1; arr[i] = arr[i-1]
void shiftByOne(vector<int> &arr, int size) {
    int tem = arr[size - 1];

    for(int i = size -1; i >= 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = tem;
}


int main() {
    // vector<int> arr = {1, 2, 3};
    // cout << uniqueEle(arr) << endl;
    // printPair(arr, arr.size());
    // printTriplet(arr, arr.size());
    // vector<int> arr = {0, 1, 0, 1, 1, 0, 0, 0, 0};
    // vector<int> ans = zeroAndOne(arr, arr.size());

    // vector<int> arr = {10, 20, 30, 40, 50};
    // shiftByOne(arr, arr.size());

    return 0;
}