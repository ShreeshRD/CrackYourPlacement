#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> mypath;
        string folder = "";
        path += "/";
        for (auto ch : path)
        {
            if (ch == '/' && folder != "")
            {
                if (folder == ".." && !mypath.empty())
                    mypath.pop_back();
                else if (folder != "." && folder != "..")
                    mypath.push_back(folder);
                folder = "";
            }
            else if (ch != '/')
                folder += ch;
        }
        string ans = "";
        if (mypath.empty())
            return "/";
        for (auto x : mypath)
            ans += "/" + x;
        return ans;
    }
};