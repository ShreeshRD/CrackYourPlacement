#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        int n = s.size();
        int a = 0, b = 1, c = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != '0')
                a = b;
            if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
                a += c;
            c = b;
            b = a;
            a = 0;
        }
        return b;
    }
};