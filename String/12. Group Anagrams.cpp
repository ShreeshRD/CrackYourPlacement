#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs)
	{
		unordered_map<string, vector<string>> mp;
		string word;
		for (auto x : strs)
		{
			word = x;
			sort(word.begin(), word.end());
			mp[word].push_back(x);
		}
		vector<vector<string>> ans;
		for (auto x : mp)
		{
			ans.push_back(x.second);
		}
		return ans;
	}
};