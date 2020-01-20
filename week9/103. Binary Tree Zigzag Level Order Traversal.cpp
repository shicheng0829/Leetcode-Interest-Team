/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s1.push(root);
        bool flag = true;
        while (!s1.empty() || !s2.empty())
        {
            vector<int> temp;
            if (flag)
            {
                while (!s1.empty())
                {
                    TreeNode *cur = s1.top();
                    s1.pop();
                    temp.push_back(cur->val);
                    if (cur->left)
                        s2.push(cur->left);
                    if (cur->right)
                        s2.push(cur->right);
                }
                flag = false;
            }
            else
            {
                while (!s2.empty())
                {
                    TreeNode *cur = s2.top();
                    s2.pop();
                    temp.push_back(cur->val);
                    if (cur->right)
                        s1.push(cur->right);
                    if (cur->left)
                        s1.push(cur->left);
                }
                flag = true;
            }
            res.push_back(temp);
        }
        return res;
    }
};