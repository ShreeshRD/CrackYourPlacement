#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

class solution
{
public:
    long long multiplyTwoLists(Node *first, Node *second)
    {
        if (first == NULL || second == NULL)
            return 0;
        long long first_num = 0, second_num = 0, mod = 1e9 + 7;
        while (first != NULL)
        {
            first_num = (first_num * 10 + first->data) % mod;
            first = first->next;
        }
        while (second != NULL)
        {
            second_num = (second_num * 10 + second->data) % mod;
            second = second->next;
        }
        first_num = (first_num * second_num) % mod;
        return first_num;
    }
};