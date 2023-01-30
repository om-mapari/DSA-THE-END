#include <iostream>
using namespace std;
#include <bits./stdc++.h>
//Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
int maxSum(int arr[], int n)
{
    int max = arr[0];
    for (size_t i = 0; i < n; i++)
    {
        int sum = arr[i];
        for (size_t j = i + 1; j < n; j++)
        {
            sum += arr[j];
            if (max < sum)
                max = sum;
        }
    }
    return max;
}
int KadanesAlgorithm(int arr[], int n)
{
    int cSum = arr[0];
    int oSum = arr[0];
    for (size_t i = 0; i < n; i++)
    {
        cSum = cSum + arr[i];
        if (arr[i] > cSum)
            cSum = arr[i];
        if (cSum > oSum)
            oSum = cSum;
    }
    return oSum;
}
int maxSubarraySum(int arr[], int n)
{
    int tillnow = arr[0];
    int cSum = arr[0];

    for (int i = 1; i < n; i++)
    {
        cSum = max(arr[i], cSum + arr[i]);
        tillnow = max(tillnow, cSum);
    }
    return tillnow;
}
int main()
{
    int arr[] = {-81, -71, 98, 55, 76, -52, 68, 15, -77, 77, -42, -70, -53, 86, 29, -30, 14, 25, -94, 73, -68, 81, 44};
    int n = 23;
    cout << maxSum(arr, n) << endl;
    cout << KadanesAlgorithm(arr, n)<<endl;
    cout <<maxSubarraySum(arr,n);
    return 0;
}