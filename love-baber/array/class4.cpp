#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: sort -ve one side and +ve one side;
// i/p-> [10, -1, 12, -2, -4, 5, 9, -123]
// o/p-> [-1, -2, -4, -123, 10, 12, 5, 9]
void sortNegativeAndPostive(vector<int> &arr, int size)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

// Problem: Sort color (0, 1, 2);
// appr: 3 pointer app, left = 0, right = length -1, index for treverse
// left side fill 0 and right side fill 2
void sortColor(vector<int> &arr, int size)
{
    int index = 0;
    int left = 0;
    int right = size - 1;

    while (index <= right)
    {
        if (arr[index] == 0)
        {
            swap(arr[index], arr[left]);
            index++;
            left++;
        }
        else if (arr[index] == 2)
        {
            swap(arr[index], arr[right]);
            right--;
            // catch -> no need to index++ because of i don't know kuch bhi ho sakta h 0, 1, 2
        }
        else
        {
            index++;
        }
    }
}

// Problem: rotate a array by k -> 189
// modules approach-> (index + k ) % size
void rotateArrayByK(vector<int> &arr, int size, int k)
{
    vector<int> ans(size);

    for (int i = 0; i < size; i++)
    {
        int index = (i + k) % size;
        ans[index] = arr[i];
    }
    arr = ans;
}

// Problem: find missing number -> 268
// count all sum 0 to size and minus given array sum , then get answer
int missingNumber(vector<int> arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    int totalSum = (size * (size + 1)) / 2;
    return totalSum - sum;
}
// third approach sort then compare O(n logn)
int missingNumberSort(vector<int> arr, int size)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i == arr[i])
            continue;
        else
            return i;
    }
    return n;
}
// second XOR approach
int missingNumberXOR(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= nums[i];
    }

    for (int i = 0; i <= n; i++)
    {
        ans ^= i;
    }
    return ans;
}

// Problem: Rearrange Array Elements by Sign 2149
// Extra space approach
vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> minArr;
    vector<int> maxArr;
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            maxArr.push_back(nums[i]);
        }
        else
        {
            minArr.push_back(nums[i]);
        }
    }

    int i = 0;
    int j = 0;

    while (i < n / 2)
    {
        ans.push_back(maxArr[i]);
        ans.push_back(minArr[i]);
        i++;
        j++;
    }
    return ans;
}

// Problem: Row With Maximum Ones(2643)
vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    vector<int> ans;
    int maxCount = INT32_MIN;
    int index = -1;

    for (int i = 0; i < mat.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 1)
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            index = i;
        }
    }

    ans.push_back(index);
    ans.push_back(maxCount);
    return ans;
}

// Problem: Rototat 2D array (48)
// first tranpose a array
// second rotate a colum
void rotate(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < row; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    // vector<int> arr = {10, -1, 12, -2, -4, 5, 9, -123};
    // int size = arr.size();
    // sortNegativeAndPostive(arr, size);
    // for(int i = 0; i < size; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // vector<int> arr = {0, 1, 2, 2, 1, 0, 0, 1, 2};
    // sortColor(arr, arr.size());
    // rotateArrayByK(arr, arr.size(), 3);
    // for(int i = 0; i < arr.size(); i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    vector<int> arr = {0, 1, 3, 4};

    cout << missingNumber(arr, arr.size()) << endl;
    return 0;
}