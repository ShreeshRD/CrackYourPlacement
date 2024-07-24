#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        s += "+0";
        stack<int> stack;
        int num = 0;
        char prev_op = '+';
        for (char c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else if (c != ' ')
            {
                if (prev_op == '+')
                    stack.push(num);
                else if (prev_op == '-')
                    stack.push(-num);
                else if (prev_op == '*')
                {
                    int top = stack.top();
                    stack.pop();
                    stack.push(top * num);
                }
                else if (prev_op == '/')
                {
                    int top = stack.top();
                    stack.pop();
                    stack.push(top / num);
                }
                prev_op = c;
                num = 0;
            }
        }
        int result = 0;
        while (!stack.empty())
        {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};