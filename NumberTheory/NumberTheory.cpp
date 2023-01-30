#include <iostream>
using namespace std;
int NumOFzeroIn_nFac(int n)
{
    int i = 5;
    int res = 0;
    for (int i = 5; i <= n; i = i*5)
    {
        res = res + n/i;
    }
    return res;
    
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
    int num = 30;
    cout<<"palindrome no = "<<reverse(num)<<endl;
    cout<<"no of zeros at the end of n! = "<<NumOFzeroIn_nFac(num)<<endl;
    return 0;
}