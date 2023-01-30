#include <iostream>
using namespace std;

int main()
{
    cout << "Enter number : ";
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << "coprime" << endl;
    };
    for (int i = 2; i*i<= n; i++)//O(n^0.5)
    {   
        if (n % i == 0)
        {
            cout << "non prime";
            break;
        }
        else
        {
            cout << "prime";
            break;
        }
    }

    return 0;
}