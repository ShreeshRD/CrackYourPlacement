#include <bits/stdc++.h>
using namespace std;

class twoStacks
{
public:
    twoStacks() : arr(100), top1(-1), top2(100), size(100)
    {
        // Initialization is done in the member initializer list
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        if (top1 < top2 - 1)
            arr[++top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        if (top1 < top2 - 1)
            arr[--top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 == -1)
            return -1;
        return arr[top1--];
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 == size)
            return -1;
        return arr[top2++];
    }

private:
    vector<int> arr;
    int top1, top2, size;
};