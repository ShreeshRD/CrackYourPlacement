#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans;
        while (columnNumber > 0)
        {
            int rem = columnNumber % 26;
            if (rem == 0)
            {
                ans = 'Z' + ans;
                columnNumber -= 26;
            }
            else
                ans = (char)(rem + 'A' - 1) + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};