class Solution
{
public:
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
            // right ordered
            else if (nums[mid] < nums[hi])
            {
                // in the right
                if (target >= nums[mid] && target <= nums[hi])
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
            // left ordered
            else
            {
                if (target <= nums[mid] && target >= nums[lo])
                {
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
        }
        return -1;
    }
};