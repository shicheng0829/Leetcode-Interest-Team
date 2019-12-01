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
    // not so good
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur && cur->next)
        {
            if (cur->next->val == val)
            {
                ListNode *next = cur->next->next;
                while (next && next->val == val)
                {
                    next = next->next;
                }
                cur->next = next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
    // good solution
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur->next)
        {
            if (cur->next->val == val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};