#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ispalindrome(string s, int i, int j)
    {
        while (i < j)
        {
            if (s.at(i) == s.at(j))
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        bool ans = true, chance = true;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                return ispalindrome(s, l + 1, r) || ispalindrome(s, l, r - 1);
            }
        }
        return true;
    }
};