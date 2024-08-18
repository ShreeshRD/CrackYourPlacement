#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size(), l = 0, maxCount = 0, ans = 0;
        vector<int> count(26);
        for (int r = 0; r < n; r++)
        {
            maxCount = max(maxCount, ++count[s[r] - 'A']);
            while (r - l + 1 - maxCount > k)
                count[s[l++] - 'A']--;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};