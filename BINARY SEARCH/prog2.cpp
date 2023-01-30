#include <bits/stdc++.h>
using namespace std;
void init_code() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

char nextGreatestLetter(vector<char> &v, char t)
{
    if (v.back() <= t) return v.front();
    int n = v.size();
    int s = 0, e = v.size() - 1;
    char result;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (v[m] == t)
            s = m + 1;
        else if (t < v[m])
        {
            result = v[m];
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return result;
}
int findPeakElement(vector<int>& v) {
    int n = v.size();
    if (n == 1)  return 0;
    if (n == 2)  return (v[0] > v[1]) ? 0 : 1;

    int s = 0, e = n - 1;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (m > 0 && m < n - 1)
        {
            if (v[m + 1] < v[m] && v[m - 1] < v[m]) return m;
            else if (v[m + 1] > v[m]) s = m + 1;
            else e = m - 1;
        }
        else if (m == 0) return (v[0] > v[1]) ? 0 : 1;
        else if (m == n - 1) return (v[n - 1] > v[n - 2]) ? n - 1 : n - 2;
    }
    return -1;
}
int main()
{
    init_code();

    // vector<char> v =  {'c', 'f', 'j'};
    // cout << nextGreatestLetter(v, 'a');
    // cout << nextGreatestLetter(v, 'c');
    // cout << nextGreatestLetter(v, 'd');
    // cout << nextGreatestLetter(v, 'i');
    // cout << nextGreatestLetter(v, 'j');
    // cout << nextGreatestLetter(v, 'f');

    vector<int> v = {3, 1, 2};
    cout << "ans => " << findPeakElement(v) << endl;


    return 0;
}