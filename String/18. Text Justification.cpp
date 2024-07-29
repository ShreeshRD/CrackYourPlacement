#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int i = 0, word_count = words.size();
        while (i < word_count)
        {
            int start = i, used = words[i].size();
            i++;
            while (i < word_count)
            {
                if (used + words[i].size() + 1 > maxWidth)
                    break;
                used += words[i].size() + 1;
                i++;
            }
            string line = words[start];
            int spacers = i - start - 1;
            if (i == word_count || spacers == 0)
            {
                for (int j = start + 1; j < i; j++)
                    line += " " + words[j];
                int pad = maxWidth - line.size();
                for (int j = 0; j < pad; j++)
                    line += " ";
            }
            else
            {
                used -= spacers;
                int spaces = maxWidth - used;
                string space = "";
                for (int j = 0; j < spaces / spacers; j++)
                    space += " ";
                for (int j = start + 1; j < i; j++)
                {
                    string new_space = space;
                    if (j - start - 1 < spaces % spacers)
                        new_space += " ";
                    line += new_space + words[j];
                }
            }
            ans.push_back(line);
        }
        return ans;
    }
};