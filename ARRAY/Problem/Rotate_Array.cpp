#include <iostream>
using namespace std;
//reversal algo for rotation of array
void reversearray_2(int a[], int start, int end)
{
    while (start <= end)
    {
        swap(a[start], a[end]);
        start++;
        end--;
    }
}

// rotate / Cyclically rotate / Forward rotate
void rotate_forward(int arr[], int n, int r) 
{
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[(i + n + r) % n] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = a[i];
    }
}
void rotate_backward(int arr[], int n, int r)
{
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[(i + n - r) % n] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = a[i];
    }
}
int main()
{
    int n = 7;
    int arr2[] = {1, 2, 3, 4, 5, 6,7};
    int r = 2;
    // method 1
    reversearray_2(arr2, 0, n - 1 - r);
    reversearray_2(arr2, n - r, n - 1);
    reversearray_2(arr2, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
        /* code */
    }
    cout << endl;

    //method 2
    rotate_forward(arr2, n, r);
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
        /* code */
    }
    cout << endl;

    //method 2
    rotate_backward(arr2, n, r);
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
        /* code */
    }

    //method 2

    return 0;
}