#include <iostream>
using namespace std;
int main()
{
    int n;
    int **ptr;
    int *ptr1;
    cin >> n;
    ptr = new int*[n];
    ptr1 = new int[n];
    for(int i = 0; i < n; i++)
    {
        ptr[i] = new int[3];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> ptr[i][0];
        cin >> ptr[i][1];
        cin >> ptr[i][2];
    }
    for(int i = 0; i < n; i++)
    {
        if(ptr[i][0] == ptr[i][2])
        {
            ptr1[i] = ptr[i][1];
        }
        else if(ptr[i][0] == ptr[i][1])
        {
            ptr1[i] = ptr[i][2];
        }
        else
        {
            ptr1[i] = ptr[i][0];
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << ptr1[i] << endl;
    }
    return 0;
}