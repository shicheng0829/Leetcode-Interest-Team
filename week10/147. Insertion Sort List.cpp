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
    // 不使用尾结点
    // ListNode* insertionSortList(ListNode* head) {
    //     ListNode* dummy = new ListNode(-1);
    //     ListNode* cur = head;
    //     while (cur)
    //     {
    //         ListNode* next = cur->next;
    //         ListNode* pre = dummy;
    //         while (pre->next && pre->next->val < cur->val)
    //             pre = pre->next;
    //         cur->next = pre->next;
    //         pre->next = cur;
    //         cur = next;
    //     }
    //     return dummy->next;
    // }
    // 使用尾结点避免额外比较（若当前节点大于尾结点，直接加在最后）
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *tail = dummy;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            if (cur->val > tail->val)
            {
                tail->next = cur;
                cur->next = nullptr;
                tail = cur;
            }
            else
            {
                ListNode *pre = dummy;
                while (pre->next && pre->next->val < cur->val)
                    pre = pre->next;
                cur->next = pre->next;
                pre->next = cur;
            }
            cur = next;
        }
        return dummy->next;
    }
};