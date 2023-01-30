#include <iostream>
using namespace std;
void HalfPyramid(int n)
{
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<i;
        }
        cout<<endl;     
    }   
}
void HalfPyramid1234(int n)
{
    int count = 1;
    // for (int i = 1; i <= n ; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout<<count;
    //         count++;
    //     }
    //     cout<<endl;       
    // }
}
int main()
{
    cout<<"Enter : ";
    int n;
    cin>>n;
    HalfPyramid(n);
    HalfPyramid1234(n);

return 0;
}