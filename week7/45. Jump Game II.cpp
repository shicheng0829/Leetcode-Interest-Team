class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int res = 0, mostRight = 0, end = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            mostRight = max(mostRight, i + nums[i]);
            if (i == end)
            {
                end = mostRight;
                ++res;
            }
        }
        return res;
    }
};