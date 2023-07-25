#include<iostream>
#include<vector>
using namespace std;
bool isValidSubSequence(vector<int> array, vector<int> sequence)
{
    int i = 0;
    for(int j = 0;i < sequence.size() && j < array.size();)
    {
        if(sequence[i] == array[j])
        {
            j++;
            i++;
        }
        else{
            j++;
        }
    }
    if(i == sequence.size())
    {
        return true;
    }
    return false;
}
int main()
{
    vector<int> array;
    vector<int> seq;
    int n;
    cout << "Enter the Element of Array: ";
    cin >> n;
    while(n != -1)
    {
        array.push_back(n);
        cout << "Enter the Element of Array: ";
        cin >> n;
    }
    cout << "Enter the Element of Sequence: ";
    cin >> n;
    while(n != -1)
    {
        seq.push_back(n);
        cout << "Enter the Element of Sequence: ";
        cin >> n;
    }
    cout << "The result is: " << isValidSubSequence(array, seq) << endl;
}