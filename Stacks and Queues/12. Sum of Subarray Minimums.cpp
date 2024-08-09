#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s1, s2;

        // Initialize the stacks and arrays
        for (int i = 0; i < n; ++i)
        {
            left[i] = i + 1;
            right[i] = n - i;
        }

        // Find the previous smaller element
        for (int i = 0; i < n; ++i)
        {
            while (!s1.empty() && arr[s1.top()] > arr[i])
            {
                s1.pop();
            }
            left[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }

        // Find the next smaller element
        for (int i = 0; i < n; ++i)
        {
            while (!s2.empty() && arr[s2.top()] > arr[i])
            {
                right[s2.top()] = i - s2.top();
                s2.pop();
            }
            s2.push(i);
        }

        // Calculate the sum of minimums
        long long sumOfMins = 0;
        for (int i = 0; i < n; ++i)
        {
            sumOfMins = (sumOfMins + (long long)arr[i] * left[i] * right[i]) % MOD;
        }

        return (int)(sumOfMins);
    }
};