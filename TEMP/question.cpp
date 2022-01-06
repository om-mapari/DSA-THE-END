#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int sol(vector<int> v)
{
    int n = v.size();
    if(n<2) return 0;
    int imin1,imin2,imax1,imax2;
    imin1=imin2=imax1=imax2= 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < v[imin1]) imin1 = i;
        if (v[i] > v[imax1]) imax1 = i;
    }
    if(imin1 == 0) imin2++;
    if(imax1 == 0) imax2++;
    for(int i=0;i<n;i++)
    {
        if(i == imin1 || i == imax1) continue;
        if (v[i] < v[imin2]) imin2 = i;
        if (v[i] > v[imax2]) imax2 = i;
    }
    return max( v[imin1] * v[imin2], v[imax1]*v[imax2]);
}

int main()
{
    vector<int> v = { -1, -4 };
    cout<<sol(v);
    return 0;
}