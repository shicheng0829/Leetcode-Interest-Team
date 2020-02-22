class Solution
{
public:
    // 位运算
    int singleNumber(vector<int> &nums)
    {
        int one = 0, two = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            one = ~two & (one ^ nums[i]);
            two = ~one & (two ^ nums[i]);
        }
        return one;
    }
    // 容易理解一点的做法
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < 32; ++i)
        {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j)
            {
                sum += (nums[j] >> i) & 1;
            }
            sum %= 3;
            if (sum != 0)
                res |= sum << i;
        }
        return res;
    }
};