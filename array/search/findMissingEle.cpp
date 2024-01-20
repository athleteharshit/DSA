#include <iostream>
#include <vector>
using namespace std;

// GFG
int findMissingElement(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;

    while(s <= e) {
        int mid = s + ((e - s) / 2);
        int diff = arr[mid] - mid;

        if(diff == 1) {
            s = mid + 1;
        }else {
            ans = mid;
            e = mid -1;
        }
    }

    return ans + 1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 6, 7, 8};
    cout << findMissingElement(arr) << endl;
    return 0;
}
