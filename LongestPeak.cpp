#include<iostream>
#include<vector>
using namespace std;
int longestPeak(vector<int> array) 
{
    int length = 1;
    int tempLength = 0;
    int temp;
    bool increase = false;
    bool decrease = false;
    bool any = false;
    for(int i = 0; i < array.size() - 1;)
    {
        while(i < array.size() - 1 && array[i] < array[i + 1])
        {
            if(!any)
            {
                length = 1;
            }
            if(decrease)
            {
                length = 1;
                decrease = false;
            }
            length++;
            i++;
            increase = true;
            any = true;
        }
        while(i < array.size() - 1 && !(array[i] < array[i + 1]))
        {
            if(array[i] == array[i + 1])
            {
                cout << "condition true\n";
                length = 0;
                any = false;
            }
            i++;
            length++;
            decrease = true;
        }
        if(increase)
        {
            increase = false;
        }
    }
    if(!decrease)
    {
        return 0;
    }
    if(!any)
    {
        return 0;
    }
    return length;
}
int main()
{
    vector<int> array = {1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, -1, -2};
    cout << longestPeak(array) << endl;
    return 0;
}