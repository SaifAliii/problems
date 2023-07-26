#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int nonCOnstructibleChange(vector<int> coins)
{

    int change = 0;
    if(coins.size() == 0)
    {
        return change + 1;
    }
    sort(coins.begin(), coins.end());
    for(int i = 0; i < coins.size()-1; i++)
    {
        change = change + coins[i];
        if(coins[i + 1] - change > 1)
        {
            return change + 1;
        } 
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter the coins: ";
    cin >> n;
    vector<int> coins;
    while(n != -1)
    {
        coins.push_back(n);
        cout << "Enter the coins: ";
        cin >> n;
    }
    cout << "The minimum amount of change that you can't create is: " << nonCOnstructibleChange(coins);
    return 0;
}