class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        if (n == 0)
            return res;
        helper(0, 0, n, "", res);
        return res;
    }
    void helper(int left, int right, int n, string cur, vector<string> &res)
    {
        if (left < right || left > n || right > n)
            return;
        if (left == right && left == n)
        {
            res.push_back(cur);
            return;
        }
        helper(left + 1, right, n, cur + "(", res);
        helper(left, right + 1, n, cur + ")", res);
    }
};