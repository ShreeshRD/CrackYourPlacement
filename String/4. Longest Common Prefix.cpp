#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";
        int min_len = strs[0].size();
        for (auto word : strs)
            min_len = min(min_len, (int)word.size());
        for (int i = 0; i < min_len; i++)
        {
            char x = strs[0][i];
            bool flag = true;
            for (auto word : strs)
            {
                if (word[i] != x)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans += x;
            else
                break;
        }
        return ans;
    }
};