/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int res = 0;
        while (head)
        {
            res = head->val + res * 2;
            head = head->next;
        }
        return res;
    }
};