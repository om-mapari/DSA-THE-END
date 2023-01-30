#include <iostream>
using namespace std;
char xor_fun(char a, char b)
{
    return (a == b) ? '0' : '1';
}

int main()
{
    string binary = "1011";
    string gray = "";

    gray += binary[0];

    for (int i = 1; i < binary.length(); i++)
    {
        gray = gray + xor_fun(gray[i - 1], binary[i]);
    }

    cout << gray;
}