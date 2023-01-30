#include <iostream>
using namespace std;

void NegLeft(int arr[],int s,int e)
{
    int i = 0;
    while (i<=e)
    {
        if(arr[i] > 0) swap(arr[i++],arr[e--]);
        else i++;
    }
    
}
int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = 9;
    NegLeft(arr,0,n-1);
    for (auto &&i : arr)
    {
        cout<<i<<" ";
    }
    
    return 0;
}