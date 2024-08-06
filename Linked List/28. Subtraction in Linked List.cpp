#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *bottom;
    Node() : data(0), next(nullptr), bottom(nullptr) {}
    Node(int x) : data(x), next(nullptr), bottom(nullptr) {}
};

class Solution
{
public:
    Node *subLinkedList(Node *head1, Node *head2)
    {
        head1 = removeLeadingZeros(head1);
        head2 = removeLeadingZeros(head2);

        int n1 = length(head1);
        int n2 = length(head2);

        if (n2 > n1 || (n1 == n2 && compare(head1, head2) < 0))
            swap(head1, head2);

        head1 = reverse(head1);
        head2 = reverse(head2);

        head1 = subtractLists(head1, head2);

        head1 = reverse(head1);
        head1 = removeLeadingZeros(head1);

        if (!head1)
            return new Node(0);

        return head1;
    }

    Node *removeLeadingZeros(Node *head)
    {
        while (head && head->data == 0)
            head = head->next;
        return head ? head : new Node(0);
    }

    int length(Node *head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    Node *reverse(Node *head)
    {
        Node *prev = NULL, *curr = head, *next;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    int compare(Node *head1, Node *head2)
    {
        while (head1 && head2)
        {
            if (head1->data != head2->data)
                return head1->data - head2->data;
            head1 = head1->next;
            head2 = head2->next;
        }
        return 0;
    }

    Node *subtractLists(Node *head1, Node *head2)
    {
        Node *tail1 = head1, *tail2 = head2;
        int carry = 0;
        while (tail1)
        {
            int t2 = tail2 ? tail2->data : 0;
            int diff = tail1->data + carry - t2;
            if (diff < 0)
            {
                diff += 10;
                carry = -1;
            }
            else
            {
                carry = 0;
            }
            tail1->data = diff;
            tail1 = tail1->next;
            if (tail2)
                tail2 = tail2->next;
        }
        return head1;
    }
};