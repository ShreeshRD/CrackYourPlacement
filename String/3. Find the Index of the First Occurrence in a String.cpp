#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n_size = needle.size(), h_size = haystack.size();
        int found = -1;
        for (int i = 0; i < h_size - n_size + 1; i++)
        {
            int j = 0;
            while (j < n_size && haystack[i + j] == needle[j])
                j++;
            if (j == n_size)
            {
                found = i;
                break;
            }
        }
        return found;
    }
};