class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        // 考虑左边界为最左的情况
        st.push(-1);
        int res = 0;
        int n = heights.size();
        // 需要将单调栈剩余元素全部pop出来，所以加入一个高度为0的元素
        heights.push_back(0);
        for (int i = 0; i <= n; ++i)
        {
            while (st.top() != -1 && heights[st.top()] > heights[i])
            {
                int h = heights[st.top()];
                st.pop();
                // 单调栈pop一个以后 st.top()为当前h对应的矩形的左边界的前一个，i为矩形的右边界的后一个
                int w = i - st.top() - 1;
                res = max(res, h * w);
            }
            st.push(i);
        }
        return res;
    }
};