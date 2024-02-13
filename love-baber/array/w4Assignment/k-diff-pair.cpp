#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Leetcode:- 532. K-diff Pairs in an Array
// first approach is sort then we use two pointer approach
int findPairs(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    int n = nums.size();
    int i = 0;
    int j = 1;
    while (j < n)
    {
        int diff = nums[j] - nums[i];
        if (diff == k)
        {
            ans.insert({nums[i], nums[j]});
            i++;
            j++;
        }
        else if (diff < k)
        {
            j++;
        }
        else
        {
            i++;
        }
        if (i == j)
            j++;
    }
    return ans.size();
}

// second approach is sort then apply bs
// a[j] - a[i] = k
// a[j] = k + a[i]

// bs for find element
int bs(vector<int> &nums, int s, int target)
{
    int e = nums.size() - 1;
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int findPairsBs(vector<int> nums, int k)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    set<pair<int, int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (bs(nums, i, nums[i] + k) != -1)
        {
            ans.insert({nums[i], nums[i] + k});
        }
    }
    return ans.size();
}

int main()
{
    vector<int> arr = {1, 1, 3, 4, 5};
    int ans = findPairsBs(arr, 2);

    cout << ans << endl;
    return 0;
}