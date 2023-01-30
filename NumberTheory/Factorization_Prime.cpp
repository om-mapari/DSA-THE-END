#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void prime_Factorization(int n)
{
    for (int i = 2; i*i<= n; i++)
    {
        int count = 1;
        if(n%i == 0)
        {
            n=n/i;
            count++;
        }
        cout<<i<<" "<<count<<endl;
    }
    
}
int main()
{
    int num;
    vector<int> v;
    cout << "Enter no. ";
    cin >> num;
    cout << "factore are = ";
    prime_Factorization(num);

    return 0;
}