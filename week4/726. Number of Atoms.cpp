class Solution
{
public:
    int i = 0;
    string countOfAtoms(string formula)
    {
        auto mp = helper(formula);
        string res;
        for (auto p : mp)
        {
            res += p.second == 1 ? p.first : p.first + to_string(p.second);
        }
        return res;
    }
    map<string, int> helper(string formula)
    {
        int N = formula.size();
        map<string, int> mp;
        while (i < N && formula[i] != ')')
        {
            if (formula[i] == '(')
            {
                i++;
                for (auto p : helper(formula))
                {
                    mp[p.first] += p.second;
                }
            }
            else
            {
                int iStart = i++;
                while (i < N && islower(formula[i]))
                    i++;
                string name = formula.substr(iStart, i - iStart);
                iStart = i;
                while (i < N && isdigit(formula[i]))
                    i++;
                int number = iStart < i ? stoi(formula.substr(iStart, i - iStart)) : 1;
                mp[name] += number;
            }
        }
        int iStart = ++i;
        while (i < N && isdigit(formula[i]))
            i++;
        if (iStart < i)
        {
            int number = stoi(formula.substr(iStart, i - iStart));
            for (auto &p : mp)
            {
                p.second *= number;
            }
        }
        return mp;
    }
};