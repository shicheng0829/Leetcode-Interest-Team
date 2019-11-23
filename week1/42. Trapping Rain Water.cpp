class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> left_to_right(n, 0);
        vector<int> right_to_left(n, 0);
        left_to_right[0] = height[0];
        for (int i = 1; i < n; ++i)
        {
            left_to_right[i] = max(left_to_right[i - 1], height[i]);
        }
        right_to_left[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            right_to_left[i] = max(right_to_left[i + 1], height[i]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            res += min(left_to_right[i], right_to_left[i]) - height[i];
        }
        return res;
    }
};