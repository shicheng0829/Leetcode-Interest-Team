class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                int k = j + 1, l = nums.size() - 1;
                while (k < l)
                {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                    {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    }
                    else if (nums[i] + nums[j] + nums[k] + nums[l] < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        auto last = unique(res.begin(), res.end());
        res.erase(last, res.end());
        return res;
    }
};