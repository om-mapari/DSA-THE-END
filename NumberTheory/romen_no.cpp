#include <bits/stdc++.h>

using namespace std;
string romen(int n)
{
    vector<pair<string, int>> vp = {
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
    string str = "";
    for (auto i : vp)
    {

        while (n >= i.second)
        {

            n = n - i.second;
            str += i.first;
        }
    }
    return str;
}

int main()
{
    int n;
    cin >> n;
    cout << romen(n) << endl;

    return 0;
}
