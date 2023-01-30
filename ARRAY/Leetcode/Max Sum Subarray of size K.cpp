class Solution
{
public:
    int maximumSumSubarray(int k, vector<int> &arr, int n)
    {
        int i = 0, j = 0, sum = 0, maxi = INT_MIN;
        while (j < n)
        {
            sum += arr[j];
            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                maxi = max(maxi, sum);
                sum -= arr[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};