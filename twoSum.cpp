#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    /*  Approach 1 i.e. using nested for loop
    time complexity O(n^2)
    space complexity O(1)
    */

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
    /*  Approach 2 i.e. using hash table
    time complexity O(n)
    space complexity O(n)
    */

    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> res;
        int find;
        unordered_map<int, int> finder;
        for (int i = 0; i < nums.size(); i++)
        {
            find = target - nums[i];
            if( finder.find(find) != finder.end() )
            {
                cout << finder[find] << endl;
                res.push_back(finder[find]);
                res.push_back(i);
                break;
            }
            finder[nums[i]] = i;
        }
        return res;
    }
    /* Approach 3 */
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
    vector<int> res = s.twoSum1(num, 9);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ", ";
    }
    

}