#include <iostream>
using namespace std;
char fun(char c)
{
    return (c == '0') ? '1' : '0';
}

int main()
{
    string gr = "1010";

    string bin;
    bin += gr[0];

    for (int i = 1; i < gr.length(); i++)
    {
        if (gr[i] == '0')
        {
            bin += bin[i - 1];
        }
        else
        {
            bin += fun(bin[i - 1]);
        }
    }

    cout << bin;
}