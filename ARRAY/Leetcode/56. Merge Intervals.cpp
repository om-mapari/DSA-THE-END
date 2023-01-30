class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &v) //O(nlogn for non sorted v)
    {
        if (v.size() == 0)
            return v;
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        vector<int> t = v[0]; //1 size temp {s,e}
        for (auto i : v)
        {
            if (i[0] <= t[1]) //check if margable => start <= e
            {
                t[1] = max(t[1], i[1]); // then redefine e = max(end,e);
            }
            else //start > e not meargable so
            {
                ans.push_back(t); //pb{s,e} and set new s,e
                t = i;
            }
        }
        ans.push_back(t);
        return ans;
    }
}; // read second soluation but more undustandable

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &v)
    {
        if (v.size() == 0)
            return v;
        sort(v.begin(), v.end());

        int n = v.size();
        vector<vector<int>> a;
        int s = v[0][0];
        int e = v[0][1];
        for (int i = 0; i < n; i++)
        {
            if (v[i][0] <= e)
            {
                e = max(e, v[i][1]);
            }
            else
            {
                a.push_back({s, e});
                s = v[i][0];
                e = v[i][1];
            }
        }
        a.push_back({s, e});
        return a;
    }
};
