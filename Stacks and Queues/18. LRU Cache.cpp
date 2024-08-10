#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node() : key(0), val(0), next(nullptr), prev(nullptr) {}
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        cap = capacity;
        left = new Node();
        right = new Node();
        left->next = right;
        right->prev = left;
    }

    void remove(Node *popme)
    {
        Node *prev = popme->prev;
        Node *next = popme->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node *newNode)
    {
        Node *prev = right->prev;
        prev->next = newNode;
        right->prev = newNode;
        newNode->prev = prev;
        newNode->next = right;
    }

    int get(int key)
    {
        if (mymap.find(key) == mymap.end())
            return -1;
        remove(mymap[key]);
        insert(mymap[key]);
        return mymap[key]->val;
    }

    void put(int key, int value)
    {
        if (mymap.find(key) != mymap.end())
            remove(mymap[key]);
        mymap[key] = new Node(key, value);
        insert(mymap[key]);
        if (mymap.size() > cap)
        {
            Node *lru = left->next;
            remove(lru);
            mymap.erase(lru->key);
        }
    }

private:
    int cap;
    unordered_map<int, Node *> mymap;
    Node *left, *right;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */