class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i)
            dp[i][0] = i;
        for (int i = 0; i <= n; ++i)
            dp[0][i] = i;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // word1和word2最后一个字母相等，从dp[i-1][j-1]过来不需要再编辑
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] - 1});
                }
                // word1和word2最后一个字母不相等，从dp[i-1][j-1]过来需要替换一个字母
                else
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        return dp[m][n];
    }
};