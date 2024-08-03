#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

class Solution
{
public:
    Node *compute(Node *head)
    {
        Node *new_head = reverseList(head);
        Node *curr = new_head;
        while (curr != NULL && curr->next != NULL)
        {
            if (curr->next->data < curr->data)
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return reverseList(new_head);
    }

    Node *reverseList(Node *head)
    {
        if (!head || !head->next)
            return head;
        Node *ans_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return ans_head;
    }
};