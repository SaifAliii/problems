#include<iostream>
#include <vector>
using namespace std;

int riverSizesHelper(vector<vector<int>>& matrix, int row, int col, int sum, vector<int>sizes)
{
    cout << "Recurrsion row: " << row << " col: " << col << "\n" ;
    if(row == matrix.size())
    {
        cout << "Row limit Reached Returning\n";
        return sum;
    }
    if(col == matrix[row].size())
    {
        cout << "Col limit Reached ";
        row++;
        if(row == matrix.size())
        {
            cout << "Row limit reached Returing After Col increment\n";
            return sum;
        }
        cout << "New Row incremented\n";
        col = 0;
    }
    if(matrix[row][col] == 1)
    {
        cout << "1 found\n";
        matrix[row][col] = 0;
        sum++;
        if(row > 0 && matrix[row - 1][col] == 1)
        {
            cout << "going up\n";
            sum = riverSizesHelper(matrix, row - 1, col, sum, sizes);
        }
        if(row < matrix.size() - 1 && matrix[row + 1][col] == 1)
        {
            cout << "going down\n";
            sum = riverSizesHelper(matrix, row + 1, col, sum, sizes);
        }
        if(col > 0 && matrix[row][col - 1] == 1)
        {
            cout << "going left\n";
            sum = riverSizesHelper(matrix, row, col - 1, sum, sizes);
        }
        if(col < matrix[row].size() - 1 && matrix[row][col + 1] == 1)
        {
            cout << "going right\n";
            sum = riverSizesHelper(matrix, row, col + 1, sum, sizes);
        }
    }
    cout << "Returning after all conditions Sum: " << sum << "\n";
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
            cout << "Parent function calling, i: " << i << " j: " << j << endl;
            sum = riverSizesHelper(matrix, i, j, sum, sizes);
            cout << "sum Returned in Parent\n";
            if(sum > 0)
            {
                sizes.push_back(sum);
            }
            
            sum = 0;
        }
    }
    return sizes;
}
vector<int> riverSizes1(vector<vector<int>> matrix) 
{
    vector<int> sizes;
    int size = 0;
    int riverSize = 0;
    bool left;    
    int tempRow, tempColumn;
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            left = false;
            size = 0;
            tempRow = i;
            tempColumn = j;
            while(matrix[tempRow][tempColumn] == 1)
            {
                matrix[tempRow][tempColumn] = 0;
                if(tempColumn > 0 && matrix[tempRow][tempColumn - 1] == 1)
                {
                    tempColumn--;
                }
                
                else if(tempColumn < matrix[tempRow].size() - 1 && matrix[tempRow][tempColumn + 1] == 1)
                {
                    tempColumn++;
                }
                else if(tempRow < matrix.size() - 1 && matrix[tempRow + 1][tempColumn] == 1)
                {
                    tempRow++;
                }
                else if(tempRow > 0 && matrix[tempRow - 1][tempColumn] == 1)
                {
                    tempRow--;
                }
                size++;
                left = true;
            }
            if(left)
            {
                sizes.push_back(size);
            }
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