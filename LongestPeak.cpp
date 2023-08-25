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
    bool down = false;
    // if(array.empty())
    // {
    //   return 0;
    // }
    for(int i = 0; i < int(array.size() - 1);)
    {
        cout << "condition true array size is: " << array.size() << "\n";
        while(i < array.size() - 1 && array[i] < array[i + 1])
        {
            if(!any)
            {
                length = 1;
            }
            if(decrease)
            {
                if(length > tempLength)
                {
                    tempLength = length;
                }
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
                if(length > tempLength)
                {
                    tempLength = length;
                    length = 1;
                }
                any = false;
                if(i + 1 == array.size()-1)
                {
                    any = true;
                }
            }
            i++;
            length++;
            decrease = true;
            down = true;
        }
    }
    cout << "temp Length: " << tempLength << " length: " << length << " and deacrese: " << decrease << endl;
    if(!decrease && tempLength == 1)
    {
        return 0;
    }
    if(!any)
    {
        return 0;
    }
    if(tempLength < length && decrease)
    {
        return length;
    }
    return tempLength;
}
int main()
{
    vector<int> array = {};
    cout << longestPeak(array) << endl;
    return 0;
}