#include <iostream>
using namespace std;
void HalfPyramid(int n){
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(j<=n-i) cout<<" ";
            else cout<<"*";
        }
        cout<<endl;
        
    }
    
}
int main(){
    cout<<"Enter : ";
    int n;
    cin>>n;
    HalfPyramid(n);

return 0;
}