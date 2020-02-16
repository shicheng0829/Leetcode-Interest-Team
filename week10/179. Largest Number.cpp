class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        auto cmp = [](string a, string b) {
            return a + b < b + a;
        };
        vector<string> vec;
        for (int i = 0; i < nums.size(); ++i)
            vec.push_back(to_string(nums[i]));
        sort(vec.begin(), vec.end(), cmp);
        string res;
        for (int i = vec.size() - 1; i >= 0; --i)
            res += vec[i];
        if (res[0] == '0')
            return "0";
        return res;
    }
};