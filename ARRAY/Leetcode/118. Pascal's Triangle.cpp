class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++)
        {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        return r;
    }
};

class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        if (n == 1)
            return {{1}};
        vector<vector<int>> v;
        v.push_back({1});    //v[0][0]
        v.push_back({1, 1}); //v[1][0],v[1][1]
        // v[2][0],v[2][1],v[2][2]
        // v[3][0],v[3][1],v[3][2],v[3][3]
        //v[2]v[1] = v[]

        for (int i = 2; i < n; i++)
        {
            vector<int> temp(i + 1); //v[2][0],v[2][1],v[2][2]
            temp[0] = temp[i] = 1;
            for (int j = 1; j < i; j++)
            {
                temp[j] = v[i - 1][j - 1] + v[i - 1][j];
            }
            v.push_back(temp);
            temp.clear();
        }
        return v;
    }
};
