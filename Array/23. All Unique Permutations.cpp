#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> uniquePerms(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(n, false);
        backtrack(arr, result, current, used);
        return result;
    }

private:
    void backtrack(const vector<int> &arr, vector<vector<int>> &result, vector<int> &current, vector<bool> &used)
    {
        if (current.size() == arr.size())
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < arr.size(); ++i)
        {
            if (used[i] || (i > 0 && arr[i] == arr[i - 1] && !used[i - 1]))
            {
                continue;
            }
            used[i] = true;
            current.push_back(arr[i]);
            backtrack(arr, result, current, used);
            current.pop_back();
            used[i] = false;
        }
    }
};