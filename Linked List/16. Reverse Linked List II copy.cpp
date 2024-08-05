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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *leftPrev = dummy, *curr;
        for (int i = 0; i < left - 1; i++)
            leftPrev = leftPrev->next;
        curr = leftPrev->next;

        ListNode *prev = NULL, *tmpNext;
        for (int i = 0; i < right - left + 1; i++)
        {
            tmpNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmpNext;
        }

        leftPrev->next->next = curr;
        leftPrev->next = prev;
        return dummy->next;
    }
};