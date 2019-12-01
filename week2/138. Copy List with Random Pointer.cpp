/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return head;
        //copy
        Node *cur = head;
        while (cur)
        {
            Node *next = cur->next;
            cur->next = new Node(cur->val, next, nullptr);
            cur = cur->next->next;
        }
        //random
        cur = head;
        while (cur)
        {
            cur->next->random = cur->random ? cur->random->next : nullptr;
            cur = cur->next->next;
        }
        //split
        cur = head;
        Node *newNode = head->next;
        Node *cur2 = head->next;
        while (cur)
        {
            cur->next = cur->next ? cur->next->next : nullptr;
            cur2->next = cur2->next ? cur2->next->next : nullptr;
            cur = cur->next;
            cur2 = cur2->next;
        }

        return newNode;
    }
};