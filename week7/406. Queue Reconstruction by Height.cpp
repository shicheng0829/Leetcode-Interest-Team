class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        auto cmp = [](vector<int> l, vector<int> r) {
            return l[0] == r[0] ? l[1] < r[1] : l[0] > r[0];
        };
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for (auto &p : people)
        {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};