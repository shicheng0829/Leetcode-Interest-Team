class Solution
{
public:
    //  计数法，时间复杂度O(n)，空间复杂度O(n);
    bool isAnagram(string s, string t)
    {
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);
        for (int i = 0; i < s.size(); ++i)
            cnt1[s[i] - 'a']++;
        for (int i = 0; i < t.size(); ++i)
            cnt2[t[i] - 'a']++;
        for (int i = 0; i < 26; ++i)
        {
            if (cnt1[i] != cnt2[i])
                return false;
        }
        return true;
    }

    // 排序法，时间复杂度O(nlogn)，空间复杂度O(1)
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};