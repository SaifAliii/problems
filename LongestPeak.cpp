#include<iostream>
#include<vector>
using namespace std;
int longestPeak(vector<int> array) 
{
    int tempLength = 1;
    int length = 0;
    int temp;
    bool status = false;
    bool dec = false;
    for(int i = 0; i < array.size() - 1;)
    {
        temp = array[i];
        cout << "temp is: " << temp << " ,and i is: " << i << endl;
        if(tempLength > length)
        {
            cout << "condition True\n";
            length = tempLength;
        }
        tempLength = 1;
        i++;
        while(i < array.size() && temp < array[i])
        {
            cout <<  "In increasing loop, temp is: "<<temp << " ,array[i] is: " << array[i] <<" and i is: " << i << endl;
            temp = array[i];
            tempLength++;
            cout << "Length is: " << tempLength << endl;
            status = true;
            i++;
        }
        while(status && i < array.size() && temp > array[i])
        {
            cout <<  "In decresing loop, temp is: "<<temp << " ,array[i] is: " << array[i] <<" and i is: " << i << endl;
            temp = array[i];
            tempLength++;
            cout << "Length is: " << tempLength << endl;
            i++;
            dec = true;
        }
        status = false;
        if(dec == false)
        {
            tempLength = 1;
        }
    }
    if(length > 3)
    {
        tempLength = length;
    }
    if(tempLength < 3)
    {
        tempLength = 0;
    }
    return tempLength;
}
int main()
{
    vector<int> array = {1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
    cout << longestPeak(array) << endl;
    return 0;
}