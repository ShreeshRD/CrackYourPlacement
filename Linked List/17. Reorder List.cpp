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
    void reorderList(ListNode *head)
    {
        deque<ListNode *> store;
        vector<ListNode *> reorder;

        ListNode *curr = head->next;
        int count = 0;
        while (curr)
        {
            count++;
            store.push_back(curr);
            curr = curr->next;
        }
        if (count < 2)
            return;
        bool flag = true;
        for (int i = 0; i < count; i++)
        {
            if (flag)
            {
                curr = store.back();
                store.pop_back();
            }
            else
            {
                curr = store.front();
                store.pop_front();
            }
            reorder.push_back(curr);
            flag ^= true;
        }
        head->next = reorder[0];
        reorder.push_back(NULL);
        for (int i = 0; i < count; i++)
            reorder[i]->next = reorder[i + 1];
        return;
    }
};