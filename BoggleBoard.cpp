#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> boggleBoard(vector<vector<char>> board, vector<string> words)
{
    vector<string> result;
    string res;
    for(int i = 0; i < words.size(); i++)
    {
        for(int l = 0; l < words[i].size(); l++)
        {
            for(int j = 0; j < board.size(); j++)
            {
                for(int k = 0; k < board[j].size(); k++)
                {
                    if(board[i][j] == words[i][l])
                    {
                        l++;
                    }
                }
            }
        }
        
    }
    
}