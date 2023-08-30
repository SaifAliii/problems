#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) 
{
    int i = 0;
    int j = 1;
    int k;
    for(; i < int(nums.size() - 1) && j < nums.size();)
    {
        k = i + 1;
        while(k < nums.size() && nums[i] == nums[k])
        {   
            k++;
        }
        if(k == nums.size())
        {
            return j;
        }
        nums[j++] = nums[k];
        i = k;
    }
    if(j == 1)
    {
        return nums.size();
    }
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return j;
}
int main()
{
    vector<int> nums = {1, 1, 2, 2 ,2, 2, 2, 2, 2, 2, 2, 2, 3};
    int uniqueElements = removeDuplicates(nums);
    cout << "\nUnique Elements: " << uniqueElements << endl;
    return 0;
}
