#include<iostream>
#include<vector>
using namespace std;
int removeElement(vector<int>& nums, int val) 
{
    int temp, j =1;
    int i = 0;
    bool status = false;
    int size = nums.size();
    if(size == 1 && nums[i] == val)
    {
        return 0;
    }
    for(; i < size && j < size ; j++)
    {
        if(nums[i] != nums[j])
        {
            if(nums[i] == val)
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                status = true;
            }
            i++;
        }
    }
    if(!status)
    {
        return 0;
    }
    return i;

}
int main()
{
    vector<int> nums = {3, 3, 3, 2, 2, 2};
    cout << "\nResult is: " << removeElement(nums, 2);
    return 0;
}