#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;
        while (!mystack.empty() && mystack.top().first <= price)
        {
            span += mystack.top().second;
            mystack.pop();
        }
        mystack.push({price, span});
        return span;
    }

private:
    stack<pair<int, int>> mystack;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */