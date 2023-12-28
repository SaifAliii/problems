#include <iostream>
using namespace std;
int main()
{
    int n;
    int n1;
    cin >> n;
    int *lens = new int[n];
    string *ptr = new string[n];
    for(int i = 0; i < n; i++)
    {
        cin >> n1;
        lens[i] = n1;
        cin.ignore();
        getline(cin, ptr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        int j = 0;
        while(ptr[i][j] != '\0')
        {
            if(ptr[i][j] == '.')
            {
                j = j + 1;
            }
            if(j + 3 < lens[i])
            {
                if(ptr[i][j + 3] == 'a' || ptr[i][j + 3] == 'e')
                {
                    ptr[i].insert(j + 2, ".");
                    lens[i] = lens[i] + 1;
                    j = j + 1;
                }
                else
                {
                    ptr[i].insert(j + 3, ".");
                    lens[i] = lens[i] + 1;
                    j = j + 2;
                }
            }
            j++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << ptr[i] << endl;
    }
    return 0;
}