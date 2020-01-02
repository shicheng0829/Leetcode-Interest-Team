class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        if (prices.empty())
            return res;
        for (int i = 1; i < prices.size(); ++i)
            //只要能获利便买入
            res += prices[i] - prices[i - 1] > 0 ? prices[i] - prices[i - 1] : 0;
        return res;
    }
};