#include<iostream>
#include<vector>
using namespace std;
vector<int> sortedSquares(vector<int>& nums) 
{
    int num;
    int temp;
    for(int i = 0, j = nums.size() - 1; i != j; )
    {   
        if( abs(nums[i]) > abs(nums[j]))
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j--;
        }
        else
        {
            j--;
        }
    }
    for(int i = 0; i < nums.size(); i++)
    {
        nums[i] = (nums[i] * nums[i]);
    }
    return nums;
}
int main()
{
    vector<int> array = {-11, -4, -1, 0, 3, 10, 12};
    array = sortedSquares(array);
    for(const auto& el: array)
    {
        cout << el;
    }
    return 0;
}