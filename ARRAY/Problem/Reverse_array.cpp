#include <iostream>
using namespace std;
void reversearray_1(int a[], int n)
{
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        swap(a[i], a[n - 1 - i]);
    }
}
void reversearray_2(int a[], int start, int end) //best
{
    while (start <= end)
    {
        swap(a[start], a[end]);
        start++;
        end--;
    }
}
int main()
{
    int m = 5;
    int arr1[] = {1, 2, 3, 4, 5};
    int n = 6;
    int arr2[] = {1, 2, 3, 4, 5, 6};
    reversearray_2(arr1, 0, m - 1);
    reversearray_2(arr2, 0, n - 1);


    //To Print Arrry
    cout << "Array 1 : ";
    for (auto &&i : arr1)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Array 2 : ";
    for (auto &&i : arr2)
    {
        cout << i << " ";
    }
    return 0;
}