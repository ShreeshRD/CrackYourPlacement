#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *bottom;
    Node() : data(0), next(nullptr), bottom(nullptr) {}
};

class Solution
{
public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root)
    {
        // Your code here
        if (!root || !root->next)
            return root;
        Node *ans = mergeTwo(root, root->next);
        Node *curr = root->next->next;
        while (curr)
        {
            ans = mergeTwo(ans, curr);
            curr = curr->next;
        }
        // Remove all next pointers
        curr = root;
        while (curr)
        {
            curr = root->next;
            root->next = NULL;
            root = curr;
        }
        return ans;
    }
    Node *mergeTwo(Node *first, Node *second)
    {
        Node *dummy = new Node();
        Node *curr = dummy;
        while (first && second)
        {
            if (first->data < second->data)
            {
                curr->bottom = first;
                first = first->bottom;
            }
            else
            {
                curr->bottom = second;
                second = second->bottom;
            }
            curr = curr->bottom;
        }
        if (first)
            curr->bottom = first;
        else if (second)
            curr->bottom = second;
        return dummy->bottom;
    }
};