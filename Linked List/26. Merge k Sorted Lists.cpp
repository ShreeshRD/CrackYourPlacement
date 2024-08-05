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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        if (n == 0)
            return NULL;
        if (n == 1)
            return lists[0];
        while (lists.size() > 1)
        {
            vector<ListNode *> mergeStep = {};
            for (int i = 0; i < lists.size(); i += 2)
            {
                ListNode *l1 = lists[i], *l2;
                if (i + 1 < lists.size())
                    l2 = lists[i + 1];
                else
                    l2 = NULL;
                mergeStep.push_back(mergeTwo(l1, l2));
            }
            lists = mergeStep;
        }
        return lists[0];
    }
    ListNode *mergeTwo(ListNode *first, ListNode *second)
    {
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;
        while (first && second)
        {
            if (first->val < second->val)
            {
                tail->next = first;
                first = first->next;
            }
            else
            {
                tail->next = second;
                second = second->next;
            }
            tail = tail->next;
        }
        if (first)
            tail->next = first;
        else if (second)
            tail->next = second;
        return dummy->next;
    }
};