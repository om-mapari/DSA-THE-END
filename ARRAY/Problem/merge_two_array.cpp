#include <iostream>
using namespace std;
void MergeArray(int a[], int al, int b[], int bl)
{
    int m[al + bl];
    int i, j, k;
    i = j = k = 0;
    while (i < al && j < bl)
    {
        if (a[i] < b[j])
        {
            m[k++] = a[i++];
        }
        else
        {
            m[k++] = b[j++];
        }
    }

    while (i < al)
    {
        m[k] = a[i];
        i++;
        k++;
    }

    while (j < bl)
    {
        m[k] = b[j];
        j++;
        k++;
    }

    for (int i = 0; i < al + bl; i++)
    {
        cout << m[i] << " ";
    }
}
int *MA(int a[], int al, int b[], int bl)
{
    int i, j, k;
    i = j = k = 0;
    // int m[al + bl];
    int *m = new int[al + bl];
    while (i < al and j < bl)
    {
        (a[i] < b[j]) ? m[k++] = a[i++] : m[k++] = b[j++];
    }
    while (i < al)
    {
        m[k++] = a[i++];
    }
    while (j < bl)
    {
        m[k++] = b[j++];
    }
    // for (int i = 0; i < al + bl; i++)
    // {
    //     cout << m[i] << " ";
    // }
    return m;
}
void Ma(int a[],int al , int b[],int bl)
{
    int i,j,k;
    i = j= k = 0;
    int m[al + bl ];
    while(i<al && j<bl) (a[i]<b[j])? m[k++]=a[i++] : m[k++]=b[j++];
    while (i<al) m[k++]=a[i++];
    while (j<bl)  m[k++]=b[j++];
    for(int i = 0 ; i<al +bl; i++) cout<<m[i]<<" ";
}
int main()
{
    int al = 5;
    int a[] = {2, 4, 5, 7, 9};
    int bl = 7;
    int b[] = {1, 3, 5, 8, 10, 11, 12, 16};
    int *p = Ma(a, al, b, bl);
    for (int i = 0; i < al + bl; i++)
    {
        cout << p[i] << " ";
    }
    return 0;
}