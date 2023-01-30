#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int Kth(int arr[], int n, int k)
{
    sort(arr,arr+n);
    return arr[k-1];
}
int kthSmallest(int arr[],int n, int k)
{
    priority_queue<int> mxhp;
    for (int i = 0; i <= n-1; i++)
    {
        mxhp.push(arr[i]);
        cout<<"i "<<i<<" "<<mxhp.size()<<endl;
        if (mxhp.size() > k)
        {
            mxhp.pop();
        }
    }
    return mxhp.top();
}
int main()
{
    int n = 6;
    int arr[] = {3, 6, 1, 5, 4, 2};
    cout << Kth(arr, n, 3) << endl;
    cout << kthSmallest(arr, n, 3);

    
    return 0;
}