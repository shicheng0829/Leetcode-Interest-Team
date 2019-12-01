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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        int carry = 0;
        while (l1 || l2 || carry != 0)
        {
            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;
            int value = l1_val + l2_val + carry;
            if (value >= 10)
            {
                value -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            cur->next = new ListNode(value);
            cur = cur->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummy->next;
    }
};