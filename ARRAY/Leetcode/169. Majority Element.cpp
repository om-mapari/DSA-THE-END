class Solution
{
public:
    int majorityElement(vector<int> &v) // O(n) and O(n)
    {
        int ele, count = 0;
        for (int candidate : v)
        {
            if (count == 0)
                ele = candidate;
            if (candidate == ele)
                count++;
            else
                count--;
        }
        return ele;
    }
};

class Solution //O(n) and O(n)
{
public:
    int majorityElement(vector<int> &v)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < v.size(); i++)
        {
            m[v[i]]++;
        }
        int maxc = 0;
        int e;
        for (auto i : m)
        {
            if (maxc < i.second)
            {
                e = i.first;
                maxc = i.second;
            }
        }
        return e;
    }
};
