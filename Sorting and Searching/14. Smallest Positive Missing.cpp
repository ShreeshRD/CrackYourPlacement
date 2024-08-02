#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= 0)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }

        for (int i = j; i < n; i++)
        {
            int val = abs(arr[i]);
            if (val <= n - j && arr[val + j - 1] > 0)
                arr[val + j - 1] *= -1;
        }

        for (int i = j; i < n; i++)
        {
            if (arr[i] > 0)
                return i - j + 1;
        }
        return n - j + 1;
    }
};