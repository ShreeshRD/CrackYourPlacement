#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        int a = 1, b = 1, c;
        for (int i = 0; i < n - 1; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};