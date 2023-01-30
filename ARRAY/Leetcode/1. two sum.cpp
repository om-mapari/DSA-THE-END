class Solution
{ //O(n) O(n)
public:
    vector<int> twoSum(vector<int> &v, int t)
    {
        int n = v.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            int x = v[i];
            int y = t - x;
            if (m.find(y) != m.end())
            {
                return {i, m[y]};
            }
            else
            {
                m.insert({v[i], i});
            }
        }
        return {-1, -1};
    }
};

class Solution // O(nlogn) O(n)
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> p;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            p.push_back({nums[i], i});
        }
        sort(p.begin(), p.end());
        int s = 0;
        int e = n - 1;
        int sum;
        while (s <= e) //two pointer approach
        {
            sum = p[s].first + p[e].first;
            if (sum > target)
                e--;
            else if (sum < target)
                s++;
            else
                return {p[s].second, p[e].second};
        }
        return {-1, -1};
    }
};