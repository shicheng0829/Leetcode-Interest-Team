/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* p1, TreeNode* p2)
    {
        if (p1 == p2 && p1 == nullptr)
            return true;
        if (p1 == nullptr || p2 == nullptr)
            return false;
        if (p1->val != p2->val)
            return false;
        return helper(p1->right, p2->left) && helper(p1->left, p2->right);
    }
};