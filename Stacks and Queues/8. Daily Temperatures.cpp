#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> mystack;
        for (int i = 0; i < n; i++)
        {
            while (!mystack.empty() && temperatures[i] > temperatures[mystack.top()])
            {
                res[mystack.top()] = i - mystack.top();
                mystack.pop();
            }
            mystack.push(i);
        }
        return res;
    }
};