class Solution {
public:
int bs(vector<int> &v, int s, int e, int t)
{
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (v[m] == t) return m;
        else if (t < v[m]) e = m - 1;
        else s = m + 1;
    }
    return -1;
}
int search(vector<int> &v, int t)
{
    if (v.front() == t) return 0;
    int n = v.size();
    int s = 0, e = n - 1;
    int zeroth;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        int prev = (m - 1 + n) % n;
        int next = (m + 1) % n;
        if (v[m] <= v[prev] && v[m] <= v[next])
        {
            zeroth = m;
            break;
        }
        else if (v[m] >= v[0]) s = m + 1;
        else if (v[m] <= v[n - 1]) e = m - 1;
    }

    return max(bs(v, 0, zeroth - 1, t), bs(v, zeroth, n - 1, t));
}

};