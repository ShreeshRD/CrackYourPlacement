#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> mystack;
        for (char ch : S)
        {
            if (ch == '+')
            {
                int a = mystack.top();
                mystack.pop();
                int &b = mystack.top();
                b += a;
            }
            else if (ch == '-')
            {
                int a = mystack.top();
                mystack.pop();
                int &b = mystack.top();
                b -= a;
            }
            else if (ch == '*')
            {
                int a = mystack.top();
                mystack.pop();
                int &b = mystack.top();
                b *= a;
            }
            else if (ch == '/')
            {
                int a = mystack.top();
                mystack.pop();
                int &b = mystack.top();
                b /= a;
            }
            else
                mystack.push(ch - '0');
        }
        return mystack.top();
    }
};