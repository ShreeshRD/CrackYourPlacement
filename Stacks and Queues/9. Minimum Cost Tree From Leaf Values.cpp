#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mctFromLeafValues(vector<int> &arr)
    {
        int ans = 0;
        stack<int> mystack;
        for (auto num : arr)
        {
            while (!mystack.empty() && mystack.top() < num)
            {
                int mid = mystack.top();
                mystack.pop();
                ans += mid * ((!mystack.empty() && mystack.top() < num) ? mystack.top() : num);
            }
            mystack.push(num);
        }
        int n = mystack.size();
        while (n >= 2)
        {
            int popped = mystack.top();
            mystack.pop();
            ans += mystack.top() * popped;
            n--;
        }
        return ans;
    }
};