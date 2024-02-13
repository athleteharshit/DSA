#include <iostream>
using namespace std;

// Remove Duplicates from Sorted Array leetcode: 26
int removeDuplicates(vector<int>& nums) {
      int j = 0;
      for(int i = 1; i < nums.size(); i++) {
          if(nums[j] != nums[i]) {
              j++;
              nums[j] = nums[i];
          }
      }
    return j+1;
}

// Maximum Average Subarray I (leetcode: 643) using sliding window problem
double findAvg(vector<int>& nums, int&k) {
        int sum = 0;
        int i = 0;
        int j = k;

        for(int l = i; l < j; l++) {
            sum += nums[l];
        }

        int maxSum = sum;
        while(j < nums.size()) {
            sum -= nums[i++];
            sum += nums[j++];
            maxSum = max(maxSum, sum);
        }

        double ans = maxSum / (double)k;
    return ans;
}

int main() {
    return 0;
}