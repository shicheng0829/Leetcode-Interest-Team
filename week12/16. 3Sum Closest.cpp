class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int begin = i + 1, end = nums.size() - 1;
            while (begin < end)
            {
                if (abs(nums[begin] + nums[end] + nums[i] - target) < diff)
                {
                    diff = abs(nums[begin] + nums[end] + nums[i] - target);
                    res = nums[begin] + nums[end] + nums[i];
                }
                if (nums[begin] + nums[end] + nums[i] < target)
                {
                    begin++;
                }
                else if (nums[begin] + nums[end] + nums[i] > target)
                {
                    end--;
                }
                else
                {
                    return target;
                }
            }
        }
        return res;
    }
};