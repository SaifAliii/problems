#include<iostream>
#include<string>
using namespace std;
bool isPalindrome(string str) {
    int start = 0;
    int end = str.size() - 1;
    bool status = true;
    while(start <= end)
    {
        if(str[start] != str[end])
        {
            status = false;
        }
        start++;
        end--;
    }
    return status;
}

int main()
{
    string s = "abca";
    cout << isPalindrome(s);
    return 0;
}