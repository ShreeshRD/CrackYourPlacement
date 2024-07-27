#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestWindow(string s, string p)
    {
        vector<int> freq(26, 0);
        vector<int> window_freq(26, 0);
        int ns = s.size(), np = p.size();

        if (ns < np)
            return "-1";

        for (auto ch : p)
            freq[ch - 'a']++;

        int l = 0, r = 0;
        int ans = -1, count = 0, window_size = INT_MAX;

        while (r < ns)
        {
            if (freq[s[r] - 'a'] > 0)
            {
                window_freq[s[r] - 'a']++;
                if (window_freq[s[r] - 'a'] <= freq[s[r] - 'a'])
                    count++;
            }
            r++;

            while (count == np)
            {
                if (r - l < window_size)
                {
                    window_size = r - l;
                    ans = l;
                }
                if (freq[s[l] - 'a'] > 0)
                {
                    window_freq[s[l] - 'a']--;
                    if (window_freq[s[l] - 'a'] < freq[s[l] - 'a'])
                        count--;
                }
                l++;
            }
        }

        if (ans == -1)
            return "-1";
        return s.substr(ans, window_size);
    }
};