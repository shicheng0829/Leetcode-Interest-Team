class Solution
{
public:
    int i = 0;
    string decodeString(string s)
    {
        string res;
        while (i < s.size() && s[i] != ']')
        {
            if (isdigit(s[i]))
            {
                int num = 0;
                while (isdigit(s[i]))
                {
                    num = 10 * num + (s[i] - '0');
                    ++i;
                }
                //skip [
                ++i;
                string temp = decodeString(s);
                //skip ]
                ++i;
                for (int i = 0; i < num; ++i)
                {
                    res += temp;
                }
            }
            else
            {
                res += s[i++];
            }
        }
        return res;
    }
};