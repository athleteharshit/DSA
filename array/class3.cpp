#include <iostream>
#include <vector>
using namespace std;

// 2D Array
// Creation:-

// int arr[3][4] = {
//     {1, 2, 3, 4},
//     {5, 6, 7, 8},
//     {9, 10, 11, 12}
// };

// point:-
// 2D array data store in a same way just like linear array
// access address -> c*i+j, c -> coloum , i = row pos , j = col pos

void print2DArrayCol(vector<vector<int>> &arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void print2DArrayRow(int arr[][4], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Problem: find target element, find max/min element, count row/col wise sum

// Problem: Diagonal print/sum
void printDiagonal(int arr[][4], int row, int col, string type)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i + j == col - 1 && type == "opp")
            {
                sum += arr[i][j];
            }
            if (i == j && type == "nor")
            {
                sum += arr[i][j];
            }
        }
    }
    cout << "Sum: " << sum << endl;
}

// Problem: Transpose a matrix
void transposeArr(vector<vector<int>> &arr, int row, int col)
{
    for(int i = 0; i < row; i++) {
        // (int j = 0; j < i; j++) pick lower trangle
        for(int j = i+1; j < col; j++) {
            int tem = arr[j][i];
            arr[j][i] = arr[i][j];
            arr[i][j] = tem;
        }
    }
}

int main()
{

    // int arr[4][4] = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12},
    //     {13, 14, 15, 16}};
    // printDiagonal(arr, 4, 4, "nor");

    // vector<vector<int>> arr = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12},
    //     {13, 14, 15, 16}};

    // print2DArrayCol(arr, arr.size(), arr[0].size());
    // transposeArr(arr, arr.size(), arr[0].size());
    // cout << "After transpose: " << endl;
    // print2DArrayCol(arr, arr.size(), arr[0].size());
    return 0;
}