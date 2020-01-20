class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i] == "+")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left + right);
            }
            else if (tokens[i] == "-")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left - right);
            }
            else if (tokens[i] == "*")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left * right);
            }
            else if (tokens[i] == "/")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left / right);
            }
            else
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};