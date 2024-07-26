#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        stack<char> mystack;

        backtrack(0, 0, n, ans, mystack);

        return ans;
    }
    void backtrack(int open, int close, int n, vector<string> &ans, stack<char> mystack)
    {
        if (open == n && open == close)
        {
            string temp = "";
            while (!mystack.empty())
            {
                temp += mystack.top();
                mystack.pop();
            }
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        if (open < n)
        {
            mystack.push('(');
            backtrack(open + 1, close, n, ans, mystack);
            mystack.pop();
        }
        if (close < open)
        {
            mystack.push(')');
            backtrack(open, close + 1, n, ans, mystack);
            mystack.pop();
        }
    }
};