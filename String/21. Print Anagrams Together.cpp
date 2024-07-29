#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        // code here
        unordered_map<string, vector<string>> groups;

        for (auto word : string_list)
        {
            string copy = word;
            sort(copy.begin(), copy.end());
            groups[copy].push_back(word);
        }

        vector<vector<string>> ans;

        for (auto val : groups)
        {
            ans.push_back(val.second);
        }

        return ans;
    }
};