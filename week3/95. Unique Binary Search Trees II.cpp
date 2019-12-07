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
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return vector<TreeNode *>{};
        return helper(1, n);
    }

    vector<TreeNode *> helper(int start, int end)
    {
        vector<TreeNode *> res;
        if (start > end)
        {
            res.push_back(nullptr);
            return res;
        }

        for (int i = start; i <= end; ++i)
        {

            vector<TreeNode *> left = helper(start, i - 1);
            vector<TreeNode *> right = helper(i + 1, end);
            for (auto l : left)
            {
                for (auto r : right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};