// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<array>
using namespace std;
int calculate(vector<int> height)
{
    int maxDistance = 0;
    for (int i = 0, j = height.size() - 1; i < j;)
    {
        if (height[i] < height[j])
        {
            if (height[i] * (j - i) > maxDistance)
            {
                maxDistance = height[i] * (j - i);
            }
            i++;
        }
        else
        {
            if (height[j] * (j - i) > maxDistance)
            {
                maxDistance = height[j] * (j - i);
            }
            j--;
        }
    }
    return maxDistance;
}
int main() {
    // Write C++ code here
    array<int, 9> arr1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    vector<int> arr(arr1.begin(), arr1.end());
    cout << calculate(arr);

    return 0;
}