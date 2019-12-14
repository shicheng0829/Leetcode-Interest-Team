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
    int res = 0;
    int longestUnivaluePath(TreeNode *root)
    {
        helper(root);
        return res;
    }
    int helper(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        int left_length = 0, right_length = 0;
        if (root->left && root->val == root->left->val)
            left_length += left + 1;
        if (root->right && root->val == root->right->val)
            right_length += right + 1;
        res = max(res, left_length + right_length);
        return max(left_length, right_length);
    }
};