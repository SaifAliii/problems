#include<iostream>
#include<vector>
using namespace std;
int removeElement(vector<int>& nums, int val) 
{
    int count = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != val)
        {
            nums[count] = nums[i];
            count++;
        }
    }
    return count;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << "\nResult is: " << removeElement(nums, 5);
    return 0;
}