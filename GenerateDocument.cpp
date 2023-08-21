#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
bool generateDocument(string characters, string document)
{
    bool status = true;
    unordered_map<char, int> counted;
    for(int i = 0; i < characters.size(); i++)
    {
        if(counted.find(characters[i]) == counted.end())
        {
             counted[characters[i]] = 1;
        }
        else
        {
            counted[characters[i]]++;
        }
    }
    for(int i = 0; i < document.size(); i++)
    {
        if(counted.find(document[i]) != counted.end())
        {
             counted[document[i]]--;
             if(counted[document[i]] < 0)
             {
                return false;
             }
        } 
    }
    return true;
}