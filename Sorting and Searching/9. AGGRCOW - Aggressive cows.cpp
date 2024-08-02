#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> stalls(n);
    for (auto &it : stalls)
        cin >> it;
    sort(stalls.begin(), stalls.end());
    int l = 1, r = stalls[n - 1] - stalls[0], result = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2, cows = 1, lastpos = 0;
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - stalls[lastpos] >= mid)
            {
                lastpos = i;
                cows++;
            }
            if (cows > c)
                break;
        }
        if (cows >= c)
        {
            l = mid + 1;
            result = mid;
        }
        else
            r = mid - 1;
    }
    cout << result << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}