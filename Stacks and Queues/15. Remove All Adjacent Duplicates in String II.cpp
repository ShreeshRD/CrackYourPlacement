#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> mystack;
        for (char ch : s)
        {
            if (!mystack.empty() && ch == mystack.top().first)
            {
                int &val = mystack.top().second;
                val++;
                if (val == k)
                    mystack.pop();
            }
            else
                mystack.push({ch, 1});
        }
        string ans;
        while (!mystack.empty())
        {
            for (int i = 0; i < mystack.top().second; i++)
                ans += mystack.top().first;
            mystack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};