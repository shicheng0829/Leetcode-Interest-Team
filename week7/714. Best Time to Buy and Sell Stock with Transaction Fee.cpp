class Solution
{
public:
    // 动态规划
    int maxProfit(vector<int> &prices, int fee)
    {
        int hold = -prices[0], cash = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            // 卖出
            cash = max(cash, hold + prices[i] - fee);
            // 买入
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }

    // 贪心 todo
};