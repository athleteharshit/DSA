#include<iostream>
#include<vector>
using namespace std;

// 658. Find K Closest Elements
// two pointer approach
class Solution {
public:
    vector<int> twoPointerFindClosestElements(vector<int> & arr, int k, int x){
        int l = 0;
        int h = arr.size() - 1;

        while(h - l >= k) {
            if(x - arr[l] > arr[h] - x) {
                l++;
            }else {
                h--;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + h + 1);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return twoPointerFindClosestElements(arr, k, x);
    }
};

// binary search approach
   int lowerbound(vector<int> &arr, int x) {
    int s = 0;
    int e = arr.size() -1;
    int ans = e;
    while(s <= e) {
        int mid = s + ((e - s)/2);
        if(arr[mid] >= x) {
            ans = mid;
            e = mid -1;
        }else if(arr[mid] < x) {
            s = mid + 1;
        }else {
            e = mid - 1;
        }
    }
    return ans;
}

vector<int> bsMethod(vector<int>& arr, int k, int x) {
    int h = lowerbound(arr, x);
    int l = h -1;
    cout << h << l << endl;
    while(k--) {
        if(l < 0) {
            h++;
        }else if (h >= arr.size()) {
            l--;
        }else if((arr[h] - x) > (x - arr[l])) {
            l--;
        }else {
            h++;
        }
    }
    return vector<int>(arr.begin() + l +1, arr.begin() + h);
}

int main() {
    vector<int> arr = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53};
    vector<int> ans = bsMethod(arr, 4, 35);

    for(auto i :ans) {
        cout << i << endl;
    }
    return 0;
}