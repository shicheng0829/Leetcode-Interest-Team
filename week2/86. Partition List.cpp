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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *less = new ListNode(-1);
        ListNode *p1 = less;
        ListNode *more = new ListNode(-1);
        ListNode *p2 = more;
        while (head)
        {
            if (head->val < x)
            {
                ListNode *next = head->next;
                p1->next = head;
                p1 = p1->next;
                head->next = nullptr;
                head = next;
            }
            else
            {
                ListNode *next = head->next;
                p2->next = head;
                p2 = p2->next;
                head->next = nullptr;
                head = next;
            }
        }
        p1->next = more->next;
        return less->next;
    }
};