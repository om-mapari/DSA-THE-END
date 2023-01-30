class Solution
{
public:
    int removeDuplicates(vector<int> &v)
    {
        if (v.size() == 0)
            return 0;
        int k = 0;
        int n = v.size();
        for (int i = 1; i < n; i++)
        {
            if (v[i] != v[k])
            {
                k++;
                v[k] = v[i];
            }
        }
        return k + 1;
    }
};