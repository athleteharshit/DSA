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

// 54. Spiral Matrix (leet code)
vector<int> spiralMatrix(vector<vector<int>> matrix) {
    vector<int> ans;
    int rowStart = 0;
    int rowEnd = matrix.size() - 1;
    int colStart = 0;
    int colEnd = matrix[0].size() - 1;
    int count = 0;
    int totalElement = matrix.size() * matrix[0].size();
    while(count < totalElement) {
         for(int i = colStart; i <= colEnd && count < totalElement; i++) {
            ans.push_back(matrix[rowStart][i]);
            count++;
         }
         rowStart++;

         for(int i = rowStart; i <= rowEnd && count < totalElement; i++) {
            ans.push_back(matrix[i][colEnd]);
            count++;
         }
         colEnd--;

         for(int i = colEnd; i >= colStart && count < totalElement; i--) {
            ans.push_back(matrix[rowEnd][i]);
            count++;
         }
         rowEnd--;

         for(int i = rowEnd; i >= rowStart && count < totalElement; i--){
            ans.push_back(matrix[i][colStart]);
            count++;
         }
         colStart++;
    }
    return ans;
}

int main()
{
    // [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    // vector<vector<int>> mat = {
    //     {1, 2, 3, 4, 5},
    //     {6, 7, 8, 9, 10},
    //     {11, 12, 13, 14, 15},
    //     {16, 17, 18, 19, 20}
    //     };
      vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
        };

    spiralMatrix(mat);
    return 0;
}