#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> calc;
        for (auto token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int op2 = calc.top();
                calc.pop();
                int op1 = calc.top();
                calc.pop();
                switch (token[0])
                {
                case '+':
                    calc.push(op1 + op2);
                    break;
                case '-':
                    calc.push(op1 - op2);
                    break;
                case '*':
                    calc.push(op1 * op2);
                    break;
                case '/':
                    calc.push(op1 / op2);
                    break;
                }
            }
            else
                calc.push(stoi(token));
        }
        return calc.top();
    }
};