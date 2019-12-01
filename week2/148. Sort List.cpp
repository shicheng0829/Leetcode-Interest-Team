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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = nullptr;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        ListNode *p1 = sortList(head);
        ListNode *p2 = sortList(slow);
        return merge(p1, p2);
    }
    ListNode *merge(ListNode *p1, ListNode *p2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (p1 && p2)
        {
            if (p1->val < p2->val)
            {
                cur->next = p1;
                p1 = p1->next;
            }
            else
            {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        cur->next = p1 ? p1 : p2;
        return dummy->next;
    }
};