#include <iostream>
#include <queue>
using namespace std;

// Problem: find kth smallest element in a Array
// first create a max heap of k element
// second traverse array if we get smaller then top element then change
int getKthSmallestElement(vector<int> arr, int n, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        int ele = arr[i];
        if (ele < pq.top())
        {
            pq.pop();
            pq.push(ele);
        }
    }

    return pq.top();
}

// Problem: find kth largest element in a Array
// first create a min heap of k element
// second traverse array if we get greter then top element then change
int getKthLargestElement(vector<int> arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        int ele = arr[i];
        if (ele > pq.top())
        {
            pq.pop();
            pq.push(ele);
        }
    }
    return pq.top();
}

// Problem: check complete binary tree(heap) or not
// first create pair class to hold max data and heap true or not
// class Node
// {
// public:
//     int data;
//     int *left;
//     int *right;
//     Node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// class Info
// {
// public:
//     int maxVal;
//     bool isHeap;

//     Info(int val, bool heap)
//     {
//         this->maxVal = val;
//         this->isHeap = heap;
//     }
// };

// Info isCompleteBinaryHeap(Node *root)
{
    if (root == NULL)
    {
        Info temp;
        temp.maxVal = INT16_MIN;
        temp.isHeap = true;
    }

    if (root->left == NULL && root->right == NULL)
    {
        Info temp;
        temp.maxVal = root->data;
        temp.isHeap = true;
    }

    Info leftAns = isCompleteBinaryHeap(root->left);
    Info rightAns = isCompleteBinaryHeap(root->right);

    if (root->data > leftAns.maxVal && root->data > rightAns.maxVal && leftAns.isHeap && rightAns.isHeap)
    {
        Info ans;
        ans.maxVal = root->data;
        ans.isHeap = true;
        return ans;
    }
    else
    {
        Info ans;
        ans.maxVal = max(leftAns.maxVal, max(rightAns.maxVal, root->data));
        ans.isHeap = false;
        return ans;
    }
}

int main()
{
    

    // vector<int> arr = {3, 2, 1, 5, 6, 4};
    // int n = arr.size();
    // int k = 2;

    // cout << getKthSmallestElement(arr, n, k) << endl;
    // cout << getKthLargestElement(arr, n, k) << endl;

    return 0;
}