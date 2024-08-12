#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> bfs;
        bfs.push(root);
        while (!bfs.empty())
        {
            Node *prev = NULL;
            int qLen = bfs.size();
            for (int i = 0; i < qLen; i++)
            {
                Node *temp = bfs.front();
                bfs.pop();
                if (temp)
                {
                    if (prev)
                        prev->next = temp;
                    prev = temp;
                    temp->next = NULL;
                    bfs.push(temp->left);
                    bfs.push(temp->right);
                }
            }
        }
        return root;
    }
};