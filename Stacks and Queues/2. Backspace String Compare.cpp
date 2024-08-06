#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> s_stack = computeString(s);
        stack<char> t_stack = computeString(t);

        if (s_stack.size() != t_stack.size())
            return false;

        while (!s_stack.empty())
        {
            if (s_stack.top() != t_stack.top())
                return false;
            s_stack.pop();
            t_stack.pop();
        }
        return true;
        ;
    }
    stack<char> computeString(string s)
    {
        stack<char> mystack;
        for (auto ch : s)
        {
            if (ch != '#')
                mystack.push(ch);
            else if (!mystack.empty())
                mystack.pop();
        }
        return mystack;
    }
};