#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        tempQueue.push(x);
        while (!mainQueue.empty())
        {
            tempQueue.push(mainQueue.front());
            mainQueue.pop();
        }
        swap(mainQueue, tempQueue);
    }

    int pop()
    {
        int val = mainQueue.front();
        mainQueue.pop();
        return val;
    }

    int top()
    {
        return mainQueue.front();
    }

    bool empty()
    {
        return mainQueue.empty();
    }

private:
    std::queue<int> mainQueue;
    std::queue<int> tempQueue;
};