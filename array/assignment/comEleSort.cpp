#include <iostream>
#include <vector>
#include <set>
using namespace std;

// gfg: Common element
// Approach: using 3 pointer O(N)
// used set for repeat number
// Note: can you take care of the duplicates without using any additional Data Structure?
// for that first remove duplicate from all the arrays
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    set<int> ans;
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            ans.insert(A[i]);
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    vector<int> st;
    for (auto i : ans)
    {
        st.push_back(i);
    }

    return st;
}

int main()
{
    return 0;
}