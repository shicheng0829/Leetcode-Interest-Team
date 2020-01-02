class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int i = 0, j = 0;
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        //尽量用最小的饼干满足合适胃口的孩子
        while (i < g.size() && j < s.size())
        {
            if (g[i] <= s[j])
            {
                ++res;
                ++i;
                ++j;
                continue;
            }
            ++j;
        }
        return res;
    }
};