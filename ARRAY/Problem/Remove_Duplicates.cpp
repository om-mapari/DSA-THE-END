#include <iostream>
using namespace std;
//Space complexity less
void RemoveD_2(int a[], int n)
{
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != a[i + 1])
        {
            a[j++] = a[i];
        }
    }
    a[j] = a[n - 1];

    for (int i = 0; i < j + 1; i++)
    {
        cout << " " << a[i];
    }
}

void RemoveD_1(int a[], int n)
{
    int temp[n];
    temp[0] = 0;
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != a[i + 1])
        {
            temp[j++] = a[i];
        }
    }
    temp[j] = a[n - 1];

    for (size_t i = 0; i < j + 1; i++)
    {
        a[i] = temp[i];
    }
    for (int i = 0; i < j + 1; i++)
    {
        cout << " " << a[i];
    }
}

int main()
{
    int x = 8;
    int arr[] = {1, 2, 2, 3, 3, 4, 5, 5};
    RemoveD_2(arr, x);

    return 0;
}