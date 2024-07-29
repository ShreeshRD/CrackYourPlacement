#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size())
            return "";
        vector<int> wfreq(58, 0), lfreq(58, 0);
        for (auto ch : t)
            wfreq[ch - 'A']++;

        int win_size = INT_MAX, l = 0, r = 0, count = 0, ans = -1;
        while (r < s.size())
        {
            if (wfreq[s[r] - 'A'] > 0)
            {
                lfreq[s[r] - 'A']++;
                if (lfreq[s[r] - 'A'] <= wfreq[s[r] - 'A'])
                    count++;
            }
            r++;
            while (count == t.size())
            {
                if (r - l < win_size)
                {
                    win_size = r - l;
                    ans = l;
                }
                if (wfreq[s[l] - 'A'] > 0)
                {
                    lfreq[s[l] - 'A']--;
                    if (lfreq[s[l] - 'A'] < wfreq[s[l] - 'A'])
                        count--;
                }
                l++;
            }
        }
        if (ans == -1)
            return "";
        return s.substr(ans, win_size);
    }
};