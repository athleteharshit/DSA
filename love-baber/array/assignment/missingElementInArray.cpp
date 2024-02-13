#include <iostream>
#include <vector>
using namespace std;

// Missing element from an array with duplicates
// [1, 3, 5, 3, 4] -> 2

// Method 1: mark element by given index
vector<int> missingEle(vector<int> arr, int n)
{
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int ele = abs(arr[i]) - 1;
        if (arr[ele] > 0)
        {
            arr[ele] *= -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int ele = arr[i];
        if (ele > 0)
        {
            ans.push_back(i + 1);
        }
    }
    return ans;
}

// Method 2: Sort and Swap technique
vector<int> missingEleSortAndSwap(vector<int> arr, int n)
{
    vector<int> ans;

    int i = 0;
    while (i < n)
    {
        int ele = arr[i] - 1;
        if (arr[i] != arr[ele])
        {
            swap(arr[i], arr[ele]);
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            ans.push_back(i + 1);
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 5, 3, 4, 6, 6};
    vector<int> ans = missingEle(arr, arr.size());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}