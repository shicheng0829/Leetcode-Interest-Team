class Solution
{
public:
    //从右向左跳，每次跳到最左的地方，看最后能否跳到原点
    bool canJump(vector<int> &nums)
    {
        int lastpos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (nums[i] + i >= lastpos)
                lastpos = i;
        }
        return lastpos == 0;
    }
};