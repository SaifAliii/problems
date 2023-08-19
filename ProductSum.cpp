#include<iostream>
#include<any>
#include<vector>
using namespace std;
int productSumHelper(vector<any> array, int depth)
{
    int sum = 0;
    for(const auto& el: array)
    {
        if(el.type() == typeid(vector<any>))
        {
            sum = sum + productSumHelper(any_cast<vector<any>>(el), depth + 1);
        }
        else
        {
            sum = sum + any_cast<int>(el);
        }
    }
    return (depth * sum);
}
int productSum(vector<any> array)
{
    int depth = 1;
    return productSumHelper(array, depth);
}
int main()
{
    vector<any> array;
    array.push_back(5);
    array.push_back(2);
    vector<any> array1;
    array1.push_back(7);
    array1.push_back(-1);
    array.push_back(array1);
    array.push_back(3);
    vector<any> array2;
    array2.push_back(6);
    vector<any> array3;
    array3.push_back(-13);
    array3.push_back(8);
    array2.push_back(array3);
    array2.push_back(4);
    array.push_back(array2);
    cout << productSum(array) << endl;
    return 0;
}