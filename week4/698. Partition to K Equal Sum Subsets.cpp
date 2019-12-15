class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k > 0)
            return false;
        int target = sum / k;
        int cur = nums.size() - 1;
        if (nums[cur] > target)
            return false;
        while (cur >= 0 && nums[cur] == target)
        {
            --k;
            --cur;
        }
        vector<int> group(k, 0);
        return helper(nums, group, cur, target);
    }
    bool helper(vector<int> &nums, vector<int> &group, int cur, int target)
    {
        if (cur < 0)
            return true;
        for (int i = 0; i < group.size(); ++i)
        {
            if (group[i] + nums[cur] <= target)
            {
                group[i] += nums[cur];
                if (helper(nums, group, cur - 1, target))
                    return true;
                group[i] -= nums[cur];
            }

            if (group[i] == 0)
                break;
        }
        return false;
    }
};