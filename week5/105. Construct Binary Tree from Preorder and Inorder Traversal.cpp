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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int preLo, int preHi, int inLo, int inHi)
    {
        if (preLo > preHi || inLo > inHi)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preLo]);
        int mid = find(inorder, inLo, inHi, preorder[preLo]);
        int left = mid - inLo;
        root->left = helper(preorder, inorder, preLo + 1, preLo + left, inLo, mid - 1);
        root->right = helper(preorder, inorder, preLo + left + 1, preHi, mid + 1, inHi);
        return root;
    }
    int find(vector<int> &inorder, int inLo, int inHi, int target)
    {
        for (int i = inLo; i <= inHi; ++i)
        {
            if (inorder[i] == target)
                return i;
        }
        return -1;
    }
};