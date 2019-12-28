class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";
        bool dp[n][n];
        memset(dp, 0, sizeof dp);
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = true;
            maxLen = 1;
            start = i;
        }
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == s[i - 1])
            {
                dp[i - 1][i] = true;
                maxLen = 2;
                start = i - 1;
            }
        }
        for (int len = 3; len <= n; ++len)
        {
            for (int j = 0; j + len - 1 < n; ++j)
            {
                if (s[j] == s[j + len - 1] && dp[j + 1][j + len - 2])
                {
                    dp[j][j + len - 1] = true;
                    if (len > maxLen)
                    {
                        maxLen = len;
                        start = j;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};