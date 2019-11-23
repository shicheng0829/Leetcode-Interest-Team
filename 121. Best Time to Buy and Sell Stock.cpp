class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX, res = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            minPrice = min(minPrice, prices[i]);
            res = max(res, prices[i] - minPrice);
        }
        return res;
    }
};