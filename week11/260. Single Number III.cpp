class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int mask = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            mask ^= nums[i];
        }
        // 取得最右边的1
        int diff = mask & (-mask);
        int x = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if ((diff & nums[i]) != 0)
            {
                x ^= nums[i];
            }
        }
        return vector<int>{x, mask ^ x};
    }
};