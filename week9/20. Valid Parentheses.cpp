class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        for (int i = 0; i < s.size(); ++i)
        {
            if (!st.empty() && mp.find(s[i]) != mp.end())
            {
                if (st.top() == mp[s[i]])
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};