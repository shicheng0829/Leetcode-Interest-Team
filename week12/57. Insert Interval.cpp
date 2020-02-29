class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        // 插入newInterval之前的interval
        int i = 0;
        for (; i < intervals.size(); ++i)
        {
            if (intervals[i][0] <= newInterval[0])
                res.push_back(intervals[i]);
            else
                break;
        }
        // 合并
        if (res.empty() || newInterval[0] > res.back()[1])
        {
            res.push_back(newInterval);
        }
        else
        {
            res.back()[1] = max(newInterval[1], res.back()[1]);
        }
        // 插入后续间隔
        for (; i < intervals.size(); ++i)
        {
            if (intervals[i][0] <= res.back()[1])
            {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};