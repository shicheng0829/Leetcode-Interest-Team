class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        vector<int> cnt(32, 0);
        for (auto num : nums)
        {
            int i = 0;
            while (num > 0)
            {
                cnt[i] += num & 1;
                num >>= 1;
                ++i;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; ++i)
        {
            res += cnt[i] * (nums.size() - cnt[i]);
        }
        return res;
    }
};