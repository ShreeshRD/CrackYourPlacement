#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(Node *head)
    {
        deque<Node *> store;
        vector<Node *> reorder;

        Node *curr = head->next;
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