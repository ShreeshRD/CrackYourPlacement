#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *left = head;
        ListNode *mid = getMid(head);
        ListNode *right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return mergeList(left, right);
    }
    ListNode *getMid(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *mergeList(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;
        while (left && right)
        {
            if (left->val < right->val)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        if (left)
            tail->next = left;
        else if (right)
            tail->next = right;
        return dummy->next;
    }
};