/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution
{
public:
    Node *pre = nullptr;
    Node *first = nullptr;
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        helper(root);
        first->left = pre;
        pre->right = first;
        return first;
    }
    void helper(Node *root)
    {
        if (root == nullptr)
            return;
        helper(root->left);
        if (pre)
        {
            root->left = pre;
            pre->right = root;
        }
        else
        {
            first = root;
        }
        pre = root;
        helper(root->right);
    }
};