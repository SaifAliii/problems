#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> array, int target) {
    int start = 0;
    int end = array.size() - 1;
    int mid = start + (end - start) / 2;                //0, 1, 21, 33, 45, 45, 61, 71, \72, 73
    if(array[start] == target)
    {
        return start;
    }
    if(array[end] == target)
    {
        return end;
    }
    while(start != mid)
    {
        if(target < array[mid])                         //start = 8 end = 9 mid = 8 target = 73
        {
            end = mid;
        }
        else if(target > array[mid])
        {
            start = mid;
        }
        else if(target == array[mid])
        {
            return mid;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
int main()
{
    vector<int> array;
    array.push_back(0);
    array.push_back(1);
    array.push_back(21);
    array.push_back(33);
    array.push_back(45);
    array.push_back(45);
    array.push_back(61);
    array.push_back(71);
    array.push_back(72);
    array.push_back(73);
    cout << binarySearch(array, 33) << endl;
    return 0;
}