#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        stack<Node *> store;
        Node *curr = head;
        while (curr)
        {
            if (curr->child)
            {
                if (curr->next)
                    store.push(curr->next);
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = NULL;
            }
            if (!curr->next && !store.empty())
            {
                curr->next = store.top();
                store.top()->prev = curr;
                store.pop();
            }
            curr = curr->next;
        }
        return head;
    }
};