/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator
{
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        helper(root);
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *cur = st.top();
        st.pop();
        if (cur->right)
            helper(cur->right);
        return cur->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !st.empty();
    }

    void helper(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */