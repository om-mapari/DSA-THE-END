class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int b = prices[0]; // prev minimum = buy
        int s;             //s = sell | sell only for privious having minimum till now
        int p = INT_MIN;   //maximise
        for (int i = 0; i < n; i++)
        {
            s = prices[i];
            if (p < (s - b))
            {
                p = s - b;
            }
            b = min(prices[i], b);
        }
        return p;
    }
};