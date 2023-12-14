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

int main() {
    vector<int> arr = {1, 2, 2, 1, 5, 5, 7};
    cout << uniqueEle(arr) << endl;
    return 0;
}