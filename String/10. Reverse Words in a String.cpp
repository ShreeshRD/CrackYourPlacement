#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words;
        string word = "";
        s += ' ';
        for (auto ch : s)
        {
            if (ch == ' ' && word != "")
            {
                words.push_back(word);
                word = "";
            }
            else if (ch != ' ')
                word += ch;
        }
        reverse(words.begin(), words.end());
        string ans = "";
        for (auto ele : words)
            ans += ele + " ";
        ans.erase(ans.size() - 1);
        return ans;
    }
};