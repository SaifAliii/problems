#include<iostream>
using namespace std;
bool isPalindrome(int x) 
{
    if( x < 0)
    {
        return false;
    }
    if(x / 10 == 0){
        return true;
    }
    int duplicateNum = x;
    int length = 0;
    while(duplicateNum != 0)
    {
        duplicateNum = duplicateNum / 10;
        length++;
    }
    int reverse = 0;
    for(int i = 0; i < length / 2; i++)
    {
        reverse = (reverse * 10) + (x % 10);
        x = x / 10;

    }
    if(length % 2 != 0)
    {
        x = x / 10;
    }
    if(x == reverse)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int x = 12345321;
    cout << isPalindrome(x);
    return 0;

}