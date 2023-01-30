class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &v)
    {
        int n = v.size();
        vector<int> left_prod(v.size());

        left_prod[0] = v[0];
        for (int i = 1; i < n; i++)
        {
            left_prod[i] = left_prod[i - 1] * v[i]; // left multi
        }

        int p = 1;
        left_prod[n - 1] = left_prod[n - 2];
        for (int i = n - 1; i > 0; i--)
        {
            left_prod[i] = left_prod[i - 1] * p; // multiplying right multi
            p = p * v[i];
        }
        left_prod[0] = p;

        return left_prod;
    }
};