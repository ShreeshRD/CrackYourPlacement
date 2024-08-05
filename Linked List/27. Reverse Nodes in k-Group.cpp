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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prevK = dummy, *curr = dummy->next;
        int count = 0;
        while (curr)
        {
            count++;
            if (count == k)
            {
                count = 0;
                ListNode *next = prevK->next, *prev = curr->next;
                prevK->next = curr;
                prevK = next;
                curr = next;
                for (int i = 0; i < k; i++)
                {
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
            }
            else
                curr = curr->next;
        }
        return dummy->next;
    }
};