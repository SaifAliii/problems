#include<iostream>
using namespace std;
int getNthFib(int n)
{
    if(n == 1)
    {
        return 0;
    }
    if(n == 2)
    {
        return 1;
    }
    int num1 = 0;
    int num2 = 1;
    int numN;
    for(int i = 3; i <=  n; i++)
    {
        num2 = num1 + num2;
        num1 = num2 - num1;
    }
    return num2;
}
int main()
{
    cout << getNthFib(7) << endl;
    return 0;
}