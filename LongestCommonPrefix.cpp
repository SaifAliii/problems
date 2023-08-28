#include<iostream>
#include<string>
#include<vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) 
{
    string res;
    if(strs.size() < 0)
    {
        return "";
    }
    if(strs.size() == 1)
    {
        return strs[0];
    }
    res = strs[0];
    string res1;
    int index = 0;
    for(int i = 1; i < strs.size(); i++)
    {
        index = 0;
        res1 = "";
        for(int j = 0; j < strs[i].size(); j++)
        {
            while(j < strs[i].size() && strs[i][j] == res[index])
            {
                res1.push_back(res[index]);
                index++;
                j++;
            }
            res = res1;
        }
        
    }        
    return res1;
}
int main()
{
    vector<string> array = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(array) << endl;
    return 0;
}
