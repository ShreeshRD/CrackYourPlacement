#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        map<Node *, Node *> track;
        track[NULL] = NULL;

        Node *curr = head;
        while (curr != NULL)
        {
            Node *copy = new Node(curr->val);
            track[curr] = copy;
            curr = curr->next;
        }

        curr = head;
        while (curr != NULL)
        {
            Node *copy = track[curr];
            copy->next = track[curr->next];
            copy->random = track[curr->random];
            curr = curr->next;
        }

        return track[head];
    }
};