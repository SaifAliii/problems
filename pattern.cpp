#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int multiplier = 1;
    int diff = n + 4;
    bool inc1 = false;
    for(int i = 0; i < n; i++)
    {
        inc1 = false;
        for(int j = 0; j < i + 1; j++)
        {
            if(j % 2 != 0)
            {
                cout << multiplier + diff << " ";
            }
            else
                cout << multiplier <<" ";
        }
        diff = diff - 2;
        multiplier++;
        cout << endl;
        // if(inc1 == true)
        // {
        //     multiplier *= 2;
        // }

    }
}