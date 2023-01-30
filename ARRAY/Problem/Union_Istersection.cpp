#include <iostream>
using namespace std;
#include <bits./stdc++.h>

int doUnion(int a[], int m, int b[], int n)  {
    vector <int> v;
    for(int i = 0;i<m;i++)
    {
        v.push_back(a[i]);
    }
    for(int i= 0;i<n;i++)
    {
        v.push_back(b[i]);
    }
    int j = 0;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        if(v[i] != v[i+1]) v[j++] = v[i];
    }
    return j;
}
int main()
{
    int a[] = {1, 1, 2, 2, 3, 3};
    int b[]= {8, 9, 7, 6, 5};
    cout<<doUnion(a,6,b,5);
}