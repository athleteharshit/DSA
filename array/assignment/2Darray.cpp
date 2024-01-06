#include <iostream>
#include <vector>
using namespace std;

void waveMatrix(vector<vector<int>> mat, int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if ((i & 1) == 0)
        {
            for (int j = 0; j < row; j++)
            {
                cout << mat[j][i] << " ";
            }
        }
        else
        {
            for (int j = row - 1; j >= 0; j--)
            {
                cout << mat[j][i] << " ";
            }
        }

        cout << endl;
    }
}

void rowWaveMatrix(vector<vector<int>> mat, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if ((i & 1) == 0)
        {
            for (int j = 0; j < col; j++)
            {
                cout << mat[i][j] << " ";
            }
        }
        else
        {
            for (int j = col - 1; j >= 0; j--)
            {
                cout << mat[i][j] << " ";
            }
        }

        cout << endl;
    }
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    rowWaveMatrix(mat, mat.size(), mat[0].size());
    return 0;
}