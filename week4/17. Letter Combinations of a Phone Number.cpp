class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> s = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits == "")
            return res;
        helper(digits, s, "", 0, res);
        return res;
    }
    void helper(string& digits, vector<string>& s, string cur, int begin, vector<string>& res)
    {
        if (begin >= digits.size())
        {
            res.push_back(cur);
            return;
        }
        string str = s[digits[begin] - '0'];
        for (int i = 0; i < str.size(); ++i)
        {
            helper(digits, s, cur + str[i], begin+1, res);
        }
    }
};