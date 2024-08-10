#include <bits/stdc++.h>
using namespace std;

class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        dfs(nestedList);
    }

    int next()
    {
        int ans = myq.front();
        myq.pop();
        return ans;
    }

    bool hasNext()
    {
        return !myq.empty();
    }

    void dfs(vector<NestedInteger> &nestedList)
    {
        for (auto ele : nestedList)
        {
            if (ele.isInteger())
                myq.push(ele.getInteger());
            else
                dfs(ele.getList());
        }
    }

private:
    queue<int> myq;
};