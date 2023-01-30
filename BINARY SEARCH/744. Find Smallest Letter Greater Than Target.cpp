class Solution {
public:
char nextGreatestLetter(vector<char> &v, char t)
{
    if(v.back() <= t) return v.front();
    int n = v.size();
    int s = 0, e = v.size() - 1;
    char result;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (v[m] == t) s = m+1;
        else if (t < v[m])
        {
            result = v[m];
            e = m - 1;
        }
        else s = m + 1;
    }
    return result;
}
};