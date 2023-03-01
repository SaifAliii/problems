#include<iostream>
int calculateGroups(int arr[], int n)
{
    int count = 1;
    int temp;
    int temp1;
    for (int i = 0, j = i + 1; j < n; i++, j++)
    {
        temp = arr[i] / 10;
        temp1 = arr[j] / 10;
        if (temp == 0)
        {
            if (temp1 != 0)
            {
                count++;
            }
        }
        else
        {
            if (temp1 != 1)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    std::cin >> n;
    int* ptr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> ptr[i];
    }
    std::cout << calculateGroups(ptr, n);

}
