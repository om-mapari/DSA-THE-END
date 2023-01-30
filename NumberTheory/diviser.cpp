#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main()
{
    int n ;
    cin >> n;

    // Find Divisor =  check 1 ---> n 
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    // optimized go upto sqrt(n)
    // coz for 36 || 2*18=36 why check for 18 again
    // prob = with prefect square
    // for 36 => 6 comes 2 x times
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0) {
            int firstMul = i;
            int secondMul = n / i;
            if (firstMul != secondMul) cout << firstMul << " " << secondMul << endl;
            else cout << firstMul << endl;
        }
    }
    cout << endl;


    return 0;
}

