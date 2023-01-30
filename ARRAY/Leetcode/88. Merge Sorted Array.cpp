class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> v(m + n);
        int x = m - 1, y = n - 1, z = m + n - 1;
        while (x >= 0 && y >= 0)
        {
            if (nums1[x] > nums2[y])
            {
                nums1[z] = nums1[x];
                x--;
                z--;
            }
            else
            {
                nums1[z] = nums2[y];
                z--;
                y--;
            }
        }
        while (x >= 0)
        {
            nums1[z] = nums1[x];
            x--;
            z--;
        }
        while (y >= 0)
        {
            nums1[z] = nums2[y];
            z--;
            y--;
        }
    }
};