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

int main() {
    return 0;
}