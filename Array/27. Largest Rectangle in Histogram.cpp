#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<pair<int, int>> mystack;
        heights.push_back(0);
        int maxArea = 0, n = heights.size(), start;
        for (int i = 0; i < n; i++)
        {
            start = i;
            while (!mystack.empty() && mystack.top().second > heights[i])
            {
                maxArea = max(maxArea, mystack.top().second * (i - mystack.top().first));
                start = mystack.top().first;
                mystack.pop();
            }
            mystack.push(make_pair(start, heights[i]));
        }
        return maxArea;
    }
};