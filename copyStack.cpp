#include<iostream>
#include<stack>
using namespace std;
void copyStack(stack<int>& s1, stack<int>& s2)
{
    int temp;
    int temp1;
    if(!s1.epmty())
    {
        temp = s1.top();
    }
    if(!s1.empty())
    {
        temp1 = s1.top();
    }
    while(!s1.empty())
    {
        s2.push(s1.top());
    }
}
int main()
{
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(8);
    stack<int> s2;
    copyStack(s1, s2);
    return 0;

}