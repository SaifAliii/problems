#include<iostream>
#include <vector>
using namespace std;

int riverSizesHelper(vector<vector<int>>& matrix, int row, int col, int sum)
{
    if(matrix[row][col] == 1)
    {
        matrix[row][col] = 0;
        sum++;
        if(row > 0 && matrix[row - 1][col] == 1)
        {
            sum = riverSizesHelper(matrix, row - 1, col, sum);
        }
        if(row < matrix.size() - 1 && matrix[row + 1][col] == 1)
        {
            sum = riverSizesHelper(matrix, row + 1, col, sum);
        }
        if(col > 0 && matrix[row][col - 1] == 1)
        {
            sum = riverSizesHelper(matrix, row, col - 1, sum);
        }
        if(col < matrix[row].size() - 1 && matrix[row][col + 1] == 1)
        {
            sum = riverSizesHelper(matrix, row, col + 1, sum);
        }
    }
    return sum;
} 
vector<int> riverSizes(vector<vector<int>> matrix) 
{
    vector<int> sizes;
    int sum = 0;
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            sum = riverSizesHelper(matrix, i, j, sum);
            if(sum > 0)
            {
                sizes.push_back(sum);
            }
            sum = 0;
        }
    }
    return sizes;
}
int main()
{
    vector<vector<int>> matrix;
    vector<int> row1;
    row1.push_back(1);
    row1.push_back(0);
    row1.push_back(0);
    row1.push_back(1);
    row1.push_back(0);
    vector<int> row2;
    vector<int> row3;
    vector<int> row4;
    vector<int> row5;
    row2.push_back(1);
    row2.push_back(0);
    row2.push_back(1);
    row2.push_back(0);
    row2.push_back(0);
    row3.push_back(0);
    row3.push_back(0);
    row3.push_back(1);
    row3.push_back(0);
    row3.push_back(1);
    row4.push_back(1);
    row4.push_back(0);
    row4.push_back(1);
    row4.push_back(0);
    row4.push_back(1);
    row5.push_back(1);
    row5.push_back(0);
    row5.push_back(1);
    row5.push_back(1);
    row5.push_back(0);
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);
    matrix.push_back(row5);
    vector<int> riverSize;
    riverSize = riverSizes(matrix);
    for(const auto& size: riverSize)
    {
        cout << size << " ";

    }
    return 0;   
}