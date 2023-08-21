#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int firstNonRepeatingCharacter(string string)
{
    unordered_map<char, int> dictionary;

    for(int i = 0; i < string.size(); i++)
    {
        if(dictionary.find(string[i]) != dictionary.end())
        {
            dictionary[string[i]]++;
        }
        else
        {
            dictionary[string[i]] = 1;
        }
    }

    for(int i = 0; i < string.size(); i++)
    {
        if((dictionary[string[i]]) == 1)
        {
            return i;
        }

    }
    return -1;
}
int main()
{
    string s = "abcbdaaafghijjkl";
    cout << firstNonRepeatingCharacter(s) << endl;
    return 0;
}