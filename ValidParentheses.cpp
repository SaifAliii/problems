#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValid(string s) 
{
    stack<char> brackets;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            brackets.push('(');
        }
        else if(s[i] == '[')
        {
            brackets.push('[');
        }
        else if(s[i] == '{')
        {
            brackets.push('{');
        }
        else if(s[i] == ')')
        {
            if( !(brackets.empty()) && brackets.top() == '(')
            {
                brackets.pop();
            }
            else
            {
                return false;
            }
        }
        else if(s[i] == '}')
        {
            if( !(brackets.empty()) && brackets.top() == '{')
            {
                brackets.pop();
            }
            else
            {
                return false;
            }
        }
        else if(s[i] == ']')
        {
            if(!(brackets.empty()) && brackets.top() == '[')
            {
                brackets.pop();
            }
            else
            {
                return false;
            }
        }
    }        
    if(brackets.empty())
    {
        return true;
    }
    return false;
}
int main()
{
    string s = "(]";
    cout << isValid(s) << endl;
    return 0;
}