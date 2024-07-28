#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        bool start = true, dot = false, num = false, expo = false, num2 = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '-' || s[i] == '+')
            {
                if (!start)
                    return false;
                start = false;
            }
            else if (s[i] == '.')
            {
                start = false;
                if (dot || expo)
                    return false;
                dot = true;
            }
            else if (s[i] == 'e' || s[i] == 'E')
            {
                if (start || !num || expo)
                    return false;
                start = true;
                expo = true;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                start = false;
                num = true;
                if (expo)
                    num2 = true;
            }
            else
            {
                return false;
            }
        }
        if (start || !num)
            return false;
        if (expo && !num2)
            return false;
        return true;
    }
};