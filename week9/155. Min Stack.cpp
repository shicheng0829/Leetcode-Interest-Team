class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> min_st;
    MinStack()
    {
    }

    void push(int x)
    {
        st.push(x);
        if (min_st.empty() || (!min_st.empty() && x <= min_st.top()))
            min_st.push(x);
    }

    void pop()
    {
        int x = st.top();
        st.pop();
        if (x == min_st.top())
            min_st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */