#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection
{
public:
    vector<pair<int, int>> vallist;
    unordered_map<int, vector<int>> mp;

    RandomizedCollection()
    {
    }

    bool insert(int val)
    {
        auto it = mp.find(val);
        if (it == mp.end())
        {
            mp[val].push_back(vallist.size());
            vallist.push_back(make_pair(val, 0));
            return true;
        }
        else
        {
            mp[val].push_back(vallist.size());
            vallist.push_back(make_pair(val, mp[val].size() - 1));
            return false;
        }
    }

    bool remove(int val)
    {
        auto it = mp.find(val);
        if (it != mp.end())
        {
            auto last = vallist.back();
            mp[last.first][last.second] = mp[val].back();
            vallist[mp[val].back()] = last;
            mp[val].pop_back();
            if (mp[val].empty())
                mp.erase(val);
            vallist.pop_back();
            return true;
        }
        return false;
    }

    int getRandom()
    {
        return vallist[rand() % vallist.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */