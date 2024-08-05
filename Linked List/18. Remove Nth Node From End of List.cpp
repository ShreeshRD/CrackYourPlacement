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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<ListNode *> store;
        ListNode *curr = head;
        int listLength = 0;
        while (curr)
        {
            listLength++;
            store.push_back(curr);
            curr = curr->next;
        }
        store.push_back(NULL);
        if (n == listLength)
            head = head->next;
        else
            store[listLength - n - 1]->next = store[listLength - n + 1];
        return head;
    }
};