#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *divide(Node *head)
    {
        Node *even = new Node(0), *odd = new Node(0);
        Node *etail = even, *otail = odd;
        while (head)
        {
            if (head->data % 2 == 0)
            {
                etail->next = head;
                etail = etail->next;
            }
            else
            {
                otail->next = head;
                otail = otail->next;
            }
            head = head->next;
        }
        etail->next = odd->next;
        otail->next = NULL;
        return even->next;
    }
};