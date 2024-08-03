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
    bool isPalindrome(ListNode *head)
    {
        stack<int> mystack;
        ListNode *curr = head;
        while (curr != NULL)
        {
            mystack.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (!mystack.empty())
        {
            if (curr->val != mystack.top())
                return false;
            curr = curr->next;
            mystack.pop();
        }
        return true;
    }
};