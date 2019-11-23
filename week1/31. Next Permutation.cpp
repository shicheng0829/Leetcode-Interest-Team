class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int k = nums.size() - 2;
        // Find the largest index k such that nums[k] < nums[k + 1].
        for (; k >= 0; --k)
        {
            if (nums[k] < nums[k + 1])
                break;
        }
        // If no such index exists, just reverse nums and done.
        if (k < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the largest index l > k such that nums[k] < nums[l].
        for (int l = nums.size() - 1; l >= 0; --l)
        {
            if (nums[l] > nums[k])
            {
                // Swap nums[k] and nums[l].
                swap(nums[l], nums[k]);
                break;
            }
        }
        // Reverse the sub-array nums[k + 1:].
        reverse(nums.begin() + k + 1, nums.end());
    }
};