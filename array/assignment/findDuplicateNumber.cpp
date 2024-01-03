#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// first approach: sort and check next number -> 287
int findDuplicateNumber(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return arr[i];
        }
    }
    return -1;
}

// second approach: using start marking
int findDuplicateNumberMarking(vector<int> nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int ele = abs(nums[i]);
        if (nums[ele] < 0)
        {
            return ele;
        }
        else
        {
            nums[ele] *= -1;
        }
    }
    return -1;
}

// Third approach: postioning method
int findDuplicateNumberMarking(vector<int> nums)
{
    while (nums[0] != nums[nums[0]])
    {
        swap(nums[0], nums[nums[0]]);
    }
    return nums[0];
}

// Fourth approach: with binary search

int main()
{
    vector<int> arr = {3, 1, 3, 4, 2};
    int ans = findDuplicateNumber(arr, arr.size());
    cout << ans << endl;
    return 0;
}