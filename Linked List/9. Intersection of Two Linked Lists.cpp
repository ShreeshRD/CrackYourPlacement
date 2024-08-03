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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int len_a = 0, len_b = 0;
        ListNode *currA = headA, *currB = headB;
        while (currA != NULL)
        {
            len_a++;
            currA = currA->next;
        }
        while (currB != NULL)
        {
            len_b++;
            currB = currB->next;
        }
        currA = headA;
        currB = headB;

        if (len_a > len_b)
        {
            for (int i = 0; i < len_a - len_b; i++)
            {
                currA = currA->next;
            }
        }
        else
        {
            for (int i = 0; i < len_b - len_a; i++)
            {
                currB = currB->next;
            }
        }

        while (currA != NULL && currB != NULL)
        {
            if (currA == currB)
            {
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        }
        return NULL;
    }
};