class Solution
{
public:
    // 调库
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return vector<int>{-1, -1};
        auto lo = lower_bound(nums.begin(), nums.end(), target);
        auto hi = upper_bound(nums.begin(), nums.end(), target);
        if (lo == nums.end() || *lo != target)
            return vector<int>{-1, -1};
        return vector<int>{lo - nums.begin(), hi - nums.begin() - 1};
    }
    // 自己实现lower_bound, upper_bound
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return vector<int>{-1, -1};
        int lo = my_lower_bound(nums, target);
        int hi = my_upper_bound(nums, target);
        if (lo >= nums.size() || nums[lo] != target)
            return vector<int>{-1, -1};
        return vector<int>{lo, hi - 1};
    }
    int my_lower_bound(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size();
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] >= target)
                hi = mid;
            else
                lo = mid + 1;
        }
        return hi;
    }

    int my_upper_bound(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size();
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target)
                hi = mid;
            else
                lo = mid + 1;
        }
        return hi;
    }
};