class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        // 符合右边大于左边规则
        vector<int> left_to_right(n, 1);
        // 符合左边大于右边规则
        vector<int> right_to_left(n, 1);
        for (int i = 1; i < n; ++i)
        {
            if (ratings[i - 1] < ratings[i])
                left_to_right[i] = left_to_right[i - 1] + 1;
        }
        for (int i = n - 1; i >= 1; --i)
        {
            if (ratings[i] < ratings[i - 1])
                right_to_left[i - 1] = right_to_left[i] + 1;
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            res += max(right_to_left[i], left_to_right[i]);
        }
        return res;
    }
};