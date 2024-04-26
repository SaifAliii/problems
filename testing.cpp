#include<iostream>
using namespace std;
int E(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return E(m-1, 1);
    else
        return E(m -1, E(m, n-1));
}
int main(){
    cout << E(1, 3);
}