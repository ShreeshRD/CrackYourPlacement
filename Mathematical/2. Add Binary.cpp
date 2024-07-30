#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans = "";
        int na = a.size(), nb = b.size(), carry = 0;
        for (int i = 0; i < max(na, nb); i++)
        {
            int a_val = 0, b_val = 0, val;
            if (i < na)
                a_val = a[na - 1 - i] - '0';
            if (i < nb)
                b_val = b[nb - 1 - i] - '0';
            val = carry + a_val + b_val;
            if (val == 0)
            {
                carry = 0;
                ans = '0' + ans;
            }
            else if (val == 1)
            {
                carry = 0;
                ans = '1' + ans;
            }
            else if (val == 2)
            {
                carry = 1;
                ans = '0' + ans;
            }
            else
            {
                carry = 1;
                ans = '1' + ans;
            }
        }
        if (carry)
            ans = '1' + ans;
        return ans;
    }
};