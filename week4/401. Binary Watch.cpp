class Solution
{
public:
    vector<int> timeTable = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
    vector<string> readBinaryWatch(int num)
    {
        vector<string> res;
        pair<int, int> time;
        helper(num, 0, time, res);
        return res;
    }
    void helper(int num, int start, pair<int, int> &time, vector<string> &res)
    {
        if (time.first >= 12 || time.second >= 60)
            return;
        if (num == 0)
        {
            res.push_back(time.second < 10 ? to_string(time.first) + ":0" + to_string(time.second) : to_string(time.first) + ":" + to_string(time.second));
            return;
        }
        for (int i = start; i < timeTable.size(); ++i)
        {
            if (i < 4)
            {
                time.first += timeTable[i];
                helper(num - 1, i + 1, time, res);
                time.first -= timeTable[i];
            }
            else
            {
                time.second += timeTable[i];
                helper(num - 1, i + 1, time, res);
                time.second -= timeTable[i];
            }
        }
    }
};