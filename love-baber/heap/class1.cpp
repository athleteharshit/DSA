#include <iostream>
using namespace std;

class Heap
{
public:
    int *arr;
    int size;
    int capicity;

    Heap(int capicity)
    {
        this->arr = new int[capicity];
        this->capicity = capicity;
        this->size = 0;
    }
    // two step process :
    // 1st: insert the data
    // 2nd: heapification (data ko shi location pr phauchanaa)
    void insert(int data)
    {
        if (size == capicity)
        {
            cout << "Heap is overflow: " << endl;
            return;
        }
        size++;
        int index = size;
        arr[index] = data;
        cout << capicity << endl;
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    int del()
    {
        if (size == 0)
        {
            cout << "Heap is Empty:" << endl;
            return -1;
        }
        int ans = arr[1];
        arr[1] = arr[size];
        size--;
        int index = 1;

        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            int largestIndex = index;

            if (leftIndex <= size && arr[largestIndex] < arr[leftIndex])
            {
                largestIndex = leftIndex;
            }
            if (rightIndex <= size && arr[largestIndex] < arr[rightIndex])
            {
                largestIndex = rightIndex;
            }

            if (index == largestIndex)
            {
                break;
            }
            else
            {
                swap(arr[index], arr[largestIndex]);
                index = largestIndex;
            }
        }

        return ans;
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Heapify way recursion
void heapFy(int *arr, int n, int index)
{
    int rightIndex = 2 * index;
    int leftIndex = 2 * index + 1;

    int largestIndex = index;

    if (leftIndex <= n && arr[leftIndex] > arr[largestIndex])
    {
        largestIndex = leftIndex;
    }

    if (rightIndex <= n && arr[rightIndex] > arr[largestIndex])
    {
        largestIndex = rightIndex;
    }

    if (index != largestIndex)
    {
        swap(arr[index], arr[largestIndex]);
        index = largestIndex;
        heapFy(arr, n, index);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapFy(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    while(n != 1) {
        swap(arr[1], arr[n]);
        n--;
        heapFy(arr, n, 1);
    }
}

int main()
{
    int size = 6;
    int arr[] = {-1, 5, 10, 15, 20, 25, 12};
    buildHeap(arr, size);
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    heapSort(arr, size);
    cout << "heap sort" << endl;
      for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    // Heap h(20);
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);

    // h.print();

    return 0;
}