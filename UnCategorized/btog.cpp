#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int numa[8] = {0}, numb[8] = {0}, diff[8] = {0};
    printf("Enter bin_1 : ");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &numa[i]);
    }
    printf("Enter bin_2 : ");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &numb[i]);
    }
    for (int i = 7; i >= 0; i--)
    {
        diff[i] = numa[i] - numb[i];
        if (diff[i] < 0)
        {
            numa[i - 1] = numa[i - 1] - 1;
        }
        diff[i] = fabs(diff[i] % 2);
    }
    printf("Sub ( bin_1 - bin_2 ) = ");
    for (int i = 0; i < 8; i++)
    {
        printf("%d", diff[i]);
    }
    getch();
    return 0;
}