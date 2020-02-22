class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0;
        int cur_num;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (cnt == 0)
            {
                cnt = 1;
                cur_num = nums[i];
            }
            else if (nums[i] == cur_num)
            {
                cnt++;
            }
            else if (nums[i] != cur_num)
            {
                cnt--;
            }
        }
        return cur_num;
    }
};