#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: find two sum (but array element position change) -> sorted array
vector<int> findPair(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<int> ans;
    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
        cout << nums[i] << nums[j] << endl;
        if ((nums[i] + nums[j]) == target)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        if ((nums[i] + nums[j]) < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return ans;
}
// Problem: two sum (1) try to solve O(N) after learn hash map

// Problem: Find pivot index (724)
// brutforce approach (left side count sum 0 to i) compare (right side count sum i+1 to n)
// if it is equal return first i
int pivotIndex(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int leftSum = 0;
        int rightSum = 0;

        for (int j = 0; j < i; j++)
        {
            leftSum += nums[j];
        }

        for (int k = i + 1; k < n; k++)
        {
            rightSum += nums[k];
        }

        if (leftSum == rightSum)
            return i;
    }
    return -1;
}

// optimize approach with Space complexity N
int pivotIndexOpp(vector<int> &nums)
{
    int n = nums.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] + nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] + nums[i + 1];
    }

    for (int i = 0; i < left.size(); i++)
    {
        if (left[i] == right[i])
            return i;
    }
    return -1;
}

// Problem: Move all negative number to the left side of an array
void leftSideNegative(vector<int> &arr, int n)
{
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

// 2nd approach Dutch's algo
void leftSideNegativeDutch(vector<int> &arr, int n)
{
    int l = 0;
    int r = n - 1;

    while (l < r)
    {
        if (arr[l] > 0)
        {
            l++;
        }
        else if (arr[r] < 0)
        {
            r--;
        }
        else
        {
            swap(arr[l], arr[r]);
        }
    }
}

int main()
{
    vector<int> arr = {1, -1, 3, 2, -7, -5, 11, 6};
    // findPair(arr, 6);
    // leftSideNegative(arr, arr.size());
    return 0;
}