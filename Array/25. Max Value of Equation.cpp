#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, int>> pq;
        int maxVal = INT_MIN;

        for (int j = 0; j < points.size(); ++j)
        {
            while (!pq.empty() && points[j][0] - pq.top().second > k)
                pq.pop();
            if (!pq.empty())
                maxVal = max(maxVal, points[j][1] + points[j][0] + pq.top().first);
            pq.push(make_pair(points[j][1] - points[j][0], points[j][0]));
        }

        return maxVal;
    }
};