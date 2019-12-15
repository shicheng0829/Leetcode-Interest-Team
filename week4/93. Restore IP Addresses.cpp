class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        helper(s, 0, 0, "", res);
        return res;
    }
    void helper(string &s, int cur, int num, string path, vector<string> &res)
    {
        if (cur == s.size() && num == 4)
        {
            res.push_back(path);
            return;
        }
        if (cur >= s.size() || num >= 4)
            return;
        for (int i = 1; i <= 3; ++i)
        {
            if (isValid(s.substr(cur, i)))
            {
                if (num == 3)
                    helper(s, cur + i, num + 1, path + s.substr(cur, i), res);
                else
                    helper(s, cur + i, num + 1, path + s.substr(cur, i) + '.', res);
            }
        }
    }

    bool isValid(string s)
    {
        if (s[0] == '0')
        {
            if (s.size() == 1)
                return true;
            else
                return false;
        }
        int num = stoi(s);
        if (num >= 0 && num <= 255)
            return true;
        else
            return false;
    }
};