#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id, dead, profit;
};

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        int latest_deadline = 0;
        for (int i = 0; i < n; i++)
            latest_deadline = max(latest_deadline, arr[i].dead);
        vector<int> slots_left;
        for (int i = 1; i <= latest_deadline; i++)
            slots_left.push_back(i);
        int jobs_done = 0, profit = 0;
        sort(arr, arr + n, [](const Job &a, const Job &b)
             { return a.profit > b.profit; });
        for (int i = 0; i < n; i++)
        {
            auto it = upper_bound(slots_left.begin(), slots_left.end(), arr[i].dead);
            if (jobs_done == latest_deadline)
                break;
            if (it != slots_left.begin())
            {
                it--;
                jobs_done++;
                profit += arr[i].profit;
                slots_left.erase(it);
            }
        }
        return {jobs_done, profit};
    }
};