#include <iostream>
using namespace std;

// get remender using binary search
int getQoutient(int divisor, int dividend)
{
  int s = 0;
  int e = divisor;
  int ans = -1;

  while (s <= e)
  {
    int mid = s + ((e - s) / 2);
    int mul = mid * divisor;

    if (mul == dividend)
    {
      return mid;
    }
    else if (mul < dividend)
    {
      ans = mid;
      s = mid + 1;
    }
    else
    {
      e = mid - 1;
    }
  }
  return ans;
}

// search nearly sorted array
int nearlySortedArr(vector<int> arr, int target)
{
  int n = arr.size();
  int s = 0;
  int e = n - 1;
  int ans = -1;

  while (s <= e)
  {
    int mid = s + ((e - s) / 2);

    if (mid + 1 < n && arr[mid + 1] == target)
    {
      return mid + 1;
    }
    else if (mid - 1 >= 0 && arr[mid - 1] == target)
    {
      return mid - 1;
    }
    else if (arr[mid] == target)
    {
      return mid;
    }
    else if (arr[mid] < target)
    {
      s = mid + 2;
    }
    else
    {
      e = mid - 2;
    }
  }

  return ans;
}

// find the odd occuring element
int firstUnpairOcc(vector<int> arr)
{
  int s = 0;
  int e = arr.size() - 1;

  while (s <= e)
  {
    int mid = s + ((e - s) / 2);
    if (s == e)
    {
      return s;
    }
    if (mid & 1)
    {
      if (arr[mid] == arr[mid - 1])
      {
        s = mid + 1;
      }
      else
      {
        e = mid - 1;
      }
    }
    else
    {
      if (arr[mid] == arr[mid + 1])
      {
        s = mid + 2;
      }
      else
      {
        e = mid;
      }
    }
  }

  return -1;
}

int main()
{
  vector<int> arr = {1, 1, 2, 5, 5, 7, 7, 10, 10, 9, 9};
  int ans = firstUnpairOcc(arr);
  cout << ans << endl;

  // vector<int> arr = {20, 10, 30, 50, 40, 70, 60};
  // int indAns = nearlySortedArr(arr, 20);
  // cout << indAns << endl;

  int divisor = -7;
  int divident = 28;

  int ans = getQoutient(abs(divisor), abs(divident));

  if ((divisor < 0 && divident > 0) && (divisor > 0 && divident < 0))
  {
    ans = 0 - ans;
  }
  cout << ans << endl;
  return 0;
}
