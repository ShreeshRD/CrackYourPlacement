#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        string ans = threeDigit(num % 1000);
        num /= 1000;
        vector<string> vals = {"Thousand", "Million", "Billion", "Trillion"};
        int count = 0;
        while (num > 0)
        {
            cout << num << " " << ans << endl;
            if (num % 1000 != 0)
                ans = threeDigit(num % 1000) + " " + vals[count] + " " + ans;
            count++;
            num /= 1000;
        }
        if (!ans.empty() && ans[ans.size() - 1] == ' ')
        {
            ans.erase(ans.size() - 1);
        }
        return ans;
    }
    string threeDigit(int mynum)
    {
        string reply = "";
        vector<string> english19 = {
            "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> englishtens = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        if (mynum / 100 > 0)
        {
            reply += english19[(mynum / 100) - 1] + " Hundred";
        }
        mynum %= 100;
        if (mynum / 10 == 1)
        {
            reply += " " + english19[mynum - 1];
            if (!reply.empty() && reply[0] == ' ')
                reply.erase(reply.begin());
            return reply;
        }
        else if (mynum / 10 > 1)
            reply += " " + englishtens[(mynum / 10) - 2];
        mynum %= 10;
        if (mynum != 0)
            reply += " " + english19[mynum - 1];
        if (!reply.empty() && reply[0] == ' ')
            reply.erase(reply.begin());
        return reply;
    }
};