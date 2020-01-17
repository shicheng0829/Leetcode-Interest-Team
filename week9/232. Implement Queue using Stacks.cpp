class MyQueue
{
public:
    /** Initialize your data structure here. */
    stack<int> st;
    stack<int> st2;
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        st.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        helper();
        int temp = st2.top();
        st2.pop();
        return temp;
    }

    /** Get the front element. */
    int peek()
    {
        helper();
        return st2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return st.empty() && st2.empty();
    }

    void helper()
    {
        if (st2.empty())
        {
            while (!st.empty())
            {
                st2.push(st.top());
                st.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */