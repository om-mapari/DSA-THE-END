#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void PrintDeque(deque<int> &dq)
{
    for (auto &&i : dq)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    // same as vector
    // insertion & access at front and back = O(1)
    // accessing element = O(1)
    deque<int> dq;
    dq.push_back(1); 
    dq.push_back(2);
    dq.push_front(3);
    PrintDeque(dq);
    // dq.pop_back();
    // dq.pop_front();

    cout<<dq.front()<<" "<< dq.back()<<endl;

    // no use of this
    cout << "\nPrint 2nd Index Element => ";
    cout << dq[2] << endl;
    return 0;
}