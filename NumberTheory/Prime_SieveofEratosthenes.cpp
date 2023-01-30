#include <iostream>
using namespace std;
#include <bits/stdc++.h> 

vector <bool> SieveofEratosthenes(int n)
{
    vector <bool> v(n+1);
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = true;
    }

    v[0] = v[1] = false;
    for (int i = 2; i*i <= n; i++)
    {
        for (int j = 2*i; j <= n; j+=i) //steps
        {
             v[j] = false;
        }
        
    }

    return v;
}


int main()
{
    int n ;
    cin>>n;
    vector <bool> isprime = SieveofEratosthenes(n);


    for (int i = 0; i < n+1; i++)
    {
        cout<<i<<" = "<<isprime[i]<<endl;
    }
    
    return 0;
}