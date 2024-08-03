#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *curr = head;
        while (curr != NULL && curr->val == val)
        {
            curr = curr->next;
        }
        if (curr == NULL)
            return curr;
        head = curr;
        while (curr->next != NULL)
        {
            if (curr->next->val == val)
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return head;
    }
};