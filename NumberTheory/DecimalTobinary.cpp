#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
string decimaltoBinary(int n)
{
    int r;
    string str = "";
    while (n != 0)
    {
        r = n%2;
        n = n/2;
        str += to_string(r);        
    }
     reverse(str.begin(),str.end());
    return str ;
}
string decimaltoOctal(int n)
{
 
    string str = "";
    int r;
    while (n != 0)
    {
        r = n%8;
        n = n/8;
        str += to_string(r); 
    } 
    reverse(str.begin(), str.end());
    return str;
    
}
int reverse(int n)
{
    int pal = n%10;
    while(n/10 != 0)
    {
        n=n/10;
        pal = pal*10 + n%10;
    }
    return pal;
}

int main()
{
   int num ;
   cin>>num;
   cout<<"Binary = "<<decimaltoBinary(num)<<endl;
   cout<<"Octal = "<<decimaltoOctal(num)<<endl;
   cout<<"reverse = "<<reverse(num)<<endl;
return 0;
}