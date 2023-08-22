#include<iostream>
#include <vector>
using namespace std;

vector<int> riverSizes(vector<vector<int>> matrix) 
{
    int riverSize = 0;
    bool left, right, up, down = true; 
    left = right = up = down;   
    int tempRow, tempColumn;
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            tempRow = i;
            tempColumn = j;
            while(matrix[tempRow][tempColumn] == 1)
            {
                if(left && tempColumn >= 0)
                {
                    tempColumn--;
                }
                else if(right && tempColumn < matrix[tempRow].size())
                {
                    tempColumn++;
                }
                else if(down && tempRow < matrix.size())
                {
                    tempRow++;
                }
                else if(up && tempRow >= 0)
                {
                    tempRow--;
                }
                

            }
        }
    }
}