class Solution
{
public:
    // 动态规划
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> up(n, 0);
        vector<int> down(n, 0);
        up[0] = 1;
        down[0] = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] < nums[i])
            {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            }
            else if (nums[i - 1] > nums[i])
            {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            }
            else
            {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[n - 1], down[n - 1]);
    }

    // 贪心
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return n;
        int prediff = nums[1] - nums[0];
        int count = (prediff == 0) ? 1 : 2;
        for (int i = 2; i < n; ++i)
        {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && prediff <= 0) || (diff < 0 && prediff >= 0))
            {
                ++count;
                prediff = diff;
            }
        }
        return count;
    }
};