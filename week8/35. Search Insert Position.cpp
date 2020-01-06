class Solution
{
public:
    // 调库
    int searchInsert(vector<int> &nums, int target)
    {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }

    // 自己实现lower_bound
    int searchInsert(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size();
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] >= target)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return hi;
    }
};