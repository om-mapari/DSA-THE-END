#include <iostream>
using namespace std;
void Triangle(int n){
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= (2*n-1) ; j++)
        {
            if(j<i || j>i) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
    

}

int main(){
    cout<<"Enter : ";
    int n;
    cin>>n;
    Triangle(n);

return 0;
}