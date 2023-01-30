#include <iostream>
using namespace std;
// r is total no. of rows and c for total no. of columns
//passing an array using pointers
void arrfunc(int *arr, int r, int c)
{
    for (int i = 0; i < r; i++)//+1
    {
        for (int j = 0; j < c; j++)
        {
           *(arr + i * c + j) = *(arr + i * c + j) + 1;
        };
    }
    for (int i = 0; i < r; i++)//print
    {
        for (int j = 0; j < c; j++)
        {
            cout << *(arr + i * c + j) << " ";
        }
        cout << endl;
    };
}
int main()
{
    int arr1[2][2] = {{1, 2}, {3, 4}};
    arrfunc((int *)arr1, 2, 2);
    return 0;
}