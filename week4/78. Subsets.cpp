class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> cur;
        helper(nums, 0, cur, res);
        return res;
    }
    void helper(vector<int> &nums, int begin, vector<int> &cur, vector<vector<int>> &res)
    {
        if (begin == nums.size())
        {
            res.push_back(cur);
            return;
        }
        helper(nums, begin + 1, cur, res);
        cur.push_back(nums[begin]);
        helper(nums, begin + 1, cur, res);
        cur.pop_back();
    }
};
