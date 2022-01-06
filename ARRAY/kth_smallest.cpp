// #include <iostream>
// using namespace std;
// #include <bits/stdc++.h>
// int part(vector<int> &v, int s, int e)
// {
//     int pindex = s;
//     int pele = v[e];
//     for (int i = s; i < e; i++)
//     {
//         if (v[i] < pele)
//         {
//             swap(v[pindex++], v[i]);
//         }
//     }
//     swap(v[pindex], v[e]);
//     return pindex;
// }
// int main()
// {

//     vector<int> v = {1, 3, 2, 4, 8, 5};
//     int p = part(v, 0, 5);
//     cout << p << endl;
//     for (auto i : v)
//         cout << i << " ";
//     cout << endl;

//     p = part(v, 0, p - 1);
//     cout << p << endl;
//     for (auto i : v)
//         cout << i << " ";
//     cout << endl;

//     p = part(v, 0, p - 1);
//     cout << p << endl;
//     for (auto i : v)
//         cout << i << " ";
//     cout << endl;
//     return 0;
// }

#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int part(vector<int> &v, int s, int e)
{
    int pindex = s;
    int pele = v[e];
    for (int i = s; i < e; i++)
    {
        if (v[i] > pele)
        {
            swap(v[pindex++], v[i]);
        }
    }
    swap(v[pindex], v[e]);
    return pindex;
}
int main()
{

    vector<int> v = {1, 3, 2, 4, 8, 5};
    int p = part(v, 0, 5);
    cout << p << endl;
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    p = part(v, 0, p + 1);
    cout << p << endl;
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    p = part(v, 0, p + 1);
    cout << p << endl;
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}