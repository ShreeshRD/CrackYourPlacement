#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(int M[INT_MAX][INT_MAX], int n, int m)
    {
        int largestArea = 0;
        vector<int> row(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == 1)
                    row[j]++;
                else
                    row[j] = 0;
            }
            largestArea = max(largestArea, getMaxArea(row));
        }
        return largestArea;
    }
    int getMaxArea(vector<int> hist)
    {
        stack<pair<int, int>> mystack;
        hist.push_back(0);
        int area = 0, n = hist.size();
        for (int i = 0; i < n; i++)
        {
            int start = i;
            while (!mystack.empty() && mystack.top().second > hist[i])
            {
                area = max(area, mystack.top().second * (i - mystack.top().first));
                start = mystack.top().first;
                mystack.pop();
            }
            mystack.push(make_pair(start, hist[i]));
        }
        return area;
    }
};