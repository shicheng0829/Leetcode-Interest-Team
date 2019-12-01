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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        ListNode *begin = head;
        while (begin)
        {
            ListNode *end = cur;
            for (int i = 0; i < k && end != nullptr; ++i)
            {
                end = end->next;
            }
            if (end == nullptr)
                break;
            ListNode *next = end->next;
            end->next = nullptr;
            reverse(begin);
            cur->next = end;
            cur = begin;
            begin->next = next;
            begin = next;
        }
        return dummy->next;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = nullptr;
        while (head)
        {
            ListNode *next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};