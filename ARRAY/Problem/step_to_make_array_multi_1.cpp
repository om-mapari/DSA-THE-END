#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main()
{
    // Q => RETURN NO OF STEP TO MAKE ARRAY MULTIPLICATION ONE => WE CAN EITHER ADD 1 OR SUB 1

    bool t = true;
    int arr[] = {0, -1, -2};
    int step = 0;
    int negc = 0;
    int z = 0;
    forf(i, 0, 3)
    {
        if (arr[i] > 0)
        {
            step += arr[i] - 1;
        }
        else if (arr[i] == 0)
        {
            z++;
        }
        else
        {
            step += ((-1) * arr[i]) - 1;
            negc++;
        }
    }
    if (negc % 2 == 0)
        cout << step + z << endl;
    else
    {
        cout << step + z << endl;
    }
}
