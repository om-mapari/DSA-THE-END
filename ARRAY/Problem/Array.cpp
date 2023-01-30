#include <iostream>
using namespace std;
void reversearray_2(int a[], int start, int end)
{
    while (start <= end)
    {
        swap(a[start], a[end]);
        start++;
        end--;
    }
}
void rotate_array(int a[], int n, int r)
{
    reversearray_2(a, 0, n - 1 - r);
    reversearray_2(a, n - r, n - 1);
    reversearray_2(a, 0, n - 1);
}

int main()
{

    int m = 5;
    int arr1[] = {1, 2, 3, 4, 5};
    int n = 6;
    int arr2[] = {1, 2, 3, 4, 5, 6};
    int choice = 0;
    int r =2;
    // do
    // {
    cout << "\n*****MAIN MENU*****" << endl;
    cout << "PRESS 1 TO Reverse Array : " << endl;
    cout << "PRESS 2 TO Fotate Array : " << endl;
    cout << "PRESS 3 TO Remove Duplicates : " << endl;
    cout << "PRESS 4 TO : " << endl;
    cout << "PRESS 5 TO : " << endl;
    cout << "PRESS 6 TO : " << endl;
    cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
    cout << "**ENTER CHOICE** : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        reversearray_2(arr1, 0, m - 1);
        reversearray_2(arr2, 0, n - 1);
        break;
    case 2:
        rotate_array(arr1,m,r);
        rotate_array(arr2,n,r);
        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    default:
        (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
        break;
    }

    // } while (choice != 0);

    //To Print Arrry
    cout << "Array 1 : ";
    for (auto &&i : arr1)
    {
        cout << i << " ";
    }
    cout << endl;
    
    cout << "Array 2 : ";
    for (auto &&i : arr2)
    {
        cout << i << " ";
    }
    return 0;
}