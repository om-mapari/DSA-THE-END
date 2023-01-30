#include <iostream>
using namespace std;
#include <bits/stdc++.h>
vector<int> factor(int n)
{
    vector<int> v;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
        }
    }
    // sort(v.begin(),v.end());
    return v;
}
vector<int> factor_opti(int n)  //O(n^0.5)
{
    vector<int> v;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if(i == n/i) continue;
            v.push_back(n / i);
        }
    }
    return v;
}
int main()
{
    int num;
    vector<int> v;
    cout << "Enter no. ";
    cin >> num;
    cout << "factore are = ";
    v = factor(num);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    v = factor_opti(num);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}