#include<iostream>
#include<vector>
using namespace std;
vector<int> bubbleSort(vector<int> array) {
  int temp;
  bool isSorted = false;
  if(array.empty())
  {
    return {};
  }
  int counter = 0;
  while(!isSorted)
  {
    isSorted = true;
    for(int i = 0; i < array.size() - 1 - counter; i++)
    {
        if(array[i] > array[i+1])
        {
            temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
            isSorted = false;
        }
    }
    counter++;
  }
  return array;
}

int main()
{
    vector<int> array;
    cout << "Enter the elements of Array: ";
    int n;
    cin >> n;
    while(n != -1)
    {
        array.push_back(n);
        cout << "Enter the elements of Array: ";
        cin >> n;   
    }
    array = bubbleSort(array);
    for(int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}