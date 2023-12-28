#include<iostream>
#include<math.h>
using namespace std;
int mySqrt(int num)
{
    int i = 0;
    while(i * i <= num)
    {
        i = i + 1;
    }
    i = i -1;
    if(i * i == num)
    {
        return i;
    }
    return -1;
    

}
int main()
{
    int n;
    int **ptr;
    int *ptr1;
    int *ans;
    cin >> n;
    ptr = new int *[n];
    ptr1 = new int[n];
    int n1;
    for(int i = 0; i < n ; i++)
    {
        cin >> n1;
        ptr1[i] = n1;
        ptr[i] = new int[n1];
        for(int j = 0; j < n1; j++)
        {
            cin >> ptr[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        int num = 0;
        for(int j = 0; j < ptr1[i]; j++)
        {
            num = num + ptr[i][j];
        }
        int num1 = mySqrt(num);
        if( num1 != -1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

    }
    return 0;
}