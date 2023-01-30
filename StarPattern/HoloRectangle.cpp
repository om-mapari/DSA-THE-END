#include <iostream>
using namespace std;
// void HoloRectangle(int r,int c){
//     for (int j= 1; i <= r; i++)
//     {
//         for (int j = 1; j <= c; j++)
//         {
//             if (i==1 || i==r){cout<<"*";}
//             else
//             {
//                 if (j==1 || j==c){cout<<"*";}
//                 else cout<<" ";         
//             }           
//         }
//         cout<<endl;     
//     }  
// }
void HoloRectangle(int r,int c){
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if(i==1 || i==r || j==1 || j==c) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
    
}

int main(){
    cout<<"Enter Row and Coloum ";
    int row,coloum;
    cin>>row>>coloum;
    HoloRectangle(row,coloum);

return 0;
}