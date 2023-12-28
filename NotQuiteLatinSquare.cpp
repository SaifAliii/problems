#include <iostream>
#include <string>
using namespace std;
int main()
{
    string inp;
    int n;
    char ***ptr;
    cin >> n;
    char * ans = new char[n + 1] ; 
    bool a;
    bool b;
    bool c;
    a = b = c = false;
    ptr = new char**[n];
    for(int i = 0; i < n;i++)
    {
        ptr[i] = new char *[3];
        for(int j = 0; j < 3; j++)
        {
            ptr[i][j] = new char[3];
        }
    }

    for(int i = 0; i < n; i++)  
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> inp;
            for(int k = 0; k < 3; k++)
            {
                ptr[i][j][k] = inp[k];
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(ptr[i][j][k] == '?')
                {
                    a = b = c = false;
                    k = 0;
                    for(; k< 3; k++)
                    {
                        if(ptr[i][j][k] == 'A')
                        {
                            a = true;
                        }
                        if(ptr[i][j][k] == 'B')
                        {
                            b = true;
                        }
                        if(ptr[i][j][k] == 'C')
                        {
                            c = true;
                        }
                    }
                    if(!a)
                    {
                        ans[i] = 'A';
                    }
                    if(!b)
                    {
                        ans[i] = 'B';
                    }
                    if(!c)
                    {
                        ans[i] = 'C';
                    }
                    
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << "\n";
    }

}