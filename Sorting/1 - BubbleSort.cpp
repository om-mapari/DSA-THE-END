#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void bubble(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
// in this we can do small optimization
// 1) loop run till n-1
// 2) for last ele will be sorted therefore n-1-i
// 3) if no swap means arr is sorted therefore break;

void bubble2(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool isSorted = true;               // optimize 1st
        for (int j = 0; j < n - 1 - i; j++) // optimize 2nd
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted)
            break;
    }
}
int main()
{
    vector<int> v = {3, 4, 6, 2, 1, 5};
    bubble2(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}