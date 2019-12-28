class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> st;
        int n = s.size();
        for (int i = 0; i < wordDict.size(); ++i)
            st.insert(wordDict[i]);
        // dp means size of index's string can break
        bool dp[n + 1];
        memset(dp, false, sizeof dp);
        dp[0] = true;
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (dp[j] && st.find(s.substr(j, i - j)) != st.end())
                {
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};