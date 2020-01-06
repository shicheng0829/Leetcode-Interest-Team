class Solution
{
public:
    // 迭代
    int search(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return -1;
    }

    // 递归
    int search(vector<int> &nums, int target)
    {
        return helper(nums, 0, nums.size() - 1, target);
    }
    int helper(vector<int> &nums, int lo, int hi, int target)
    {
        if (lo > hi)
            return -1;
        int mid = (lo + hi) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            return helper(nums, mid + 1, hi, target);
        else
            return helper(nums, lo, mid - 1, target);
    }
};