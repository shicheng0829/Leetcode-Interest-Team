class Solution
{
public:
    //找到gas - cost最小值的下个位置
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int sum = 0;
        int min_sum = INT_MAX;
        int start = -1;
        for (int i = 0; i < gas.size(); ++i)
        {
            sum += gas[i];
            sum -= cost[i];
            if (sum < min_sum)
            {
                start = i + 1;
                min_sum = sum;
            }
        }
        if (sum < 0)
            return -1;
        if (start == gas.size())
            return 0;
        return start;
    }
};