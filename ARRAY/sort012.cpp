#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void sort012(int arr[], int n)
{
    int s = 0, m = 0, e = n - 1;
    while (m <= e)
    {
        if (arr[m] == 0)
        {
            swap(arr[s++], arr[m++]);
        }
        else if (arr[m] == 1)
        {
            m++;
        }
        else if (arr[m] == 2)
        {
            swap(arr[e--], arr[m]);
        }
    }
}
void printUnion(int arr1[], int arr2[], int n, int m)
{
    int i, j;
    i = j = 0;
    vector<int> v;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            v.push_back(arr1[i++]);
        }
        else if (arr1[i] > arr2[j])
        {
            v.push_back(arr2[j++]);
        }
        else if (arr1[i] == arr2[j])
        {
            v.push_back(arr1[i++]);
            j++;
        }
    }
    while (i < n)
    {
        v.push_back(arr1[i++]);
    }
    while (j < m)
    {
        v.push_back(arr2[j++]);
    }
    cout << i << j << endl;
    for (auto &&i : v)
    {
        cout << i << " ";
    }
}
void printInter(int arr1[], int arr2[], int n, int m)
{
    int i, j;
    i = j = 0;
    vector<int> v;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else if (arr1[i] == arr2[j])
        {
            v.push_back(arr1[i++]);
            j++;
        }
    }

    cout << i << j << endl;
    for (auto &&i : v)
    {
        cout << i << " ";
    }
}
int doUnion(int a[], int n, int b[], int m)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    return s.size();
}
int main()
{
    // int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // sort012(arr, n);
    // for (auto &&i : arr)
    // {
    //     std::cout << i << " ";
    // }

    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    // Function calling
    printUnion(arr1, arr2, n, m);
    printInter(arr1, arr2, n, m);

    return 0;
}
