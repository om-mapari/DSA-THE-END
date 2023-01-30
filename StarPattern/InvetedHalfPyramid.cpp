#include <iostream>
using namespace std;
void InvertedHalfPyramid(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int  j = n; j >= i; j--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
int main(){
    cout<<"Enter : ";
    int n;
    cin>>n;
    InvertedHalfPyramid(n);

return 0;
}