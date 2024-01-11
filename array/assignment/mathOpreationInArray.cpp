#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Add two numbers represented by two arrays (GFG)
string calc_Sum(int *a, int n, int *b, int m)
{
    string ans;
    int i = n - 1;
    int j = m - 1;
    int carry = 0;

    while (i >= 0 && j >= 0)
    {
        int sum = a[i] + b[j] + carry;
        int dig = sum % 10;
        ans.push_back(dig + '0');
        carry = sum / 10;
        i--;
        j--;
    }

    while (i >= 0)
    {
        int sum = a[i] + carry;
        int dig = sum % 10;
        ans.push_back(dig + '0');
        carry = sum / 10;
        i--;
    }

    while (j >= 0)
    {
        int sum = b[j] + carry;
        int dig = sum % 10;
        ans.push_back(dig + '0');
        carry = sum / 10;
        j--;
    }

    if (carry)
    {
        ans.push_back(carry + '0');
    }

    while (ans[ans.size() - 1] == '0')
    {
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

// Factorials of large numbers (GFG)
vector<int> factorial(int N)
{
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            int mul = ans[j] * i + carry;
            ans[j] = mul % 10;
            carry = mul / 10;
        }
        //  if(carry) {
        //      ans.push_back(carry);
        //  }
        //  carry = 0;
        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}