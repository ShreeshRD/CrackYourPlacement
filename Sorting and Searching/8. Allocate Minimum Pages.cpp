#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m)
    {
        if (m > n)
            return -1;
        long long l = *max_element(arr, arr + n), r = accumulate(arr, arr + n, 0LL);
        if (n == m)
            return l;
        while (l < r)
        {
            long long mid = l + (r - l) / 2;
            int student_count = 1;
            long long curr_val = 0;

            for (int book_no = 0; book_no < n; ++book_no)
            {
                if (curr_val + arr[book_no] > mid)
                {
                    student_count++;
                    curr_val = 0;
                }
                curr_val += arr[book_no];
            }

            if (student_count <= m)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};