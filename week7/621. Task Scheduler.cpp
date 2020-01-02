class Solution
{
public:
    //总时间和最大次数任务有关，但要考虑最大次数任务重复和n较小的情况
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> mp(26, 0);
        for (int i = 0; i < tasks.size(); ++i)
            mp[tasks[i] - 'A']++;
        sort(mp.begin(), mp.end());
        int maxcount = 1;
        for (int i = 24; i >= 0; --i)
        {
            if (mp[i] == mp[i + 1])
                maxcount++;
            else
                break;
        }
        return max((mp[25] - 1) * (n + 1) + maxcount, (int)tasks.size());
    }
};