#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int knightDialer(int n)
    {
        if (n == 1)
            return 10;

        // A -> Corners, B -> Left-Right, C -> Top-Bottom, D -> Zero
        vector<int> jumps = {4, 2, 2, 1};
        int mod = 1e9 + 7;

        for (int i = 1; i < n; i++)
        {
            vector<int> next_jump(4);
            next_jump[0] = ((2 * jumps[1]) % mod + (2 * jumps[2]) % mod) % mod;
            next_jump[1] = ((2 * jumps[3]) % mod + jumps[0]) % mod;
            next_jump[2] = jumps[0];
            next_jump[3] = jumps[1];
            jumps = next_jump;
        }

        int ans = 0;
        for (auto ele : jumps)
            ans = (ans + ele) % mod;
        return ans;
    }
};