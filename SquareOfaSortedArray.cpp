#include<iostream>
#include<vector>
using namespace std;
vector<int> sortedSquares(vector<int>& nums) 
{
    vector<int> res(nums.size());
    int index = nums.size() - 1;
    for(int i = 0, j = nums.size() - 1; i <= j; )
    {   
        
        if((nums[i] * nums[i]) > (nums[j] * nums[j]))
        {
            res[index] = (nums[i] * nums[i]);
            i++;
        }
        else
        {
            res[index] = (nums[j] * nums[j]);
            j--;
        }
        index--;
    }
    return res;
}
int main()
{
    vector<int> array = {-7,-3,2,3,11};
    array = sortedSquares(array);
    for(const auto& el: array)
    {
        cout << el << " ";
    }
    return 0;
}