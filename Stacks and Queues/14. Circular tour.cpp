#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution
{
public:
    int tour(petrolPump p[], int n)
    {
        int balance = 0, deficit = 0, front = 0, rear = 0;
        while (rear < n)
        {
            balance += p[rear].petrol - p[rear].distance;
            if (balance < 0)
            {
                deficit += balance;
                balance = 0;
                front = rear + 1;
            }
            rear++;
        }
        if (balance + deficit < 0)
            return -1;
        return front;
    }
};