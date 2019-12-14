class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        helper(nums, 0, res);
        return res;
    }
    void helper(vector<int> &nums, int cur, vector<vector<int>> &res)
    {
        if (cur == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int i = cur; i < nums.size(); ++i)
        {
            swap(nums[cur], nums[i]);
            helper(nums, cur + 1, res);
            swap(nums[cur], nums[i]);
        }
    }
};