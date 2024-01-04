#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// first way to solve by O(N^2)

// second way to solve by O(N) and S(N)
// GFG Q: First Repeating Element
int fun(vector<int> arr, int n) {
    // we can also use array for hash insted of hash(unordered map)
    unordered_map<int, int> hash;

    for(int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    for(int i = 0; i < n; i++) {
        if(hash[arr[i]] > 1) {
            return i+1;
        }
    }
    return -1;
}

int main() { 
    vector<int> arr = {1, 5, 3, 4, 3, 5, 6};
    cout << fun(arr, arr.size()) << endl;
    return 0;
}