#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};
int main()
{
    vector<int> num;
    int n;
    cout << "Enter any number ";
    cin >> n;
    while (n != -1)
    {
        num.push_back(n);
        cout << "Enter any number ";
        cin >> n;
    }
    Solution s;
    vector<int> res = s.twoSum(num, 9);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ", ";
    }
    

}