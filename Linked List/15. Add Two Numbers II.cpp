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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> first, second;
        while (l1)
        {
            first.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            second.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode *ans = NULL;
        while (!first.empty() || !second.empty() || carry)
        {
            int a = 0, b = 0;
            if (!first.empty())
            {
                a = first.top();
                first.pop();
            }
            if (!second.empty())
            {
                b = second.top();
                second.pop();
            }
            carry += a + b;
            ListNode *newNode = new ListNode(carry % 10);
            carry /= 10;
            newNode->next = ans;
            ans = newNode;
        }
        return ans;
    }
};