#include <iostream>
using namespace std;

struct Node
{
    int key;
    struct Node* pleft;
    struct Node* pright;
};
typedef struct Node NODE;
typedef NODE* TREE;

void CreateTree (TREE &t)
{
    t = NULL;
}

NODE* CreateNode (int x)
{
    NODE* p = new NODE;
    if (p == NULL)
    {
        return NULL;
    }
    p->key = x;
    p->pleft = p->pright = NULL;
    return p;
}

int AddNode (TREE &t, int x)
{
    if (t != NULL)
    {
        if (t->key == x)
        {
            return 0;
        }
        if (x < t->key)
        {
            return AddNode (t->pleft,x);
        }
        else
        {
            return AddNode (t->pright,x);
        }
    }
    t = CreateNode (x);
    return 1;
}

void ThayThe (TREE &p, TREE &t)
{
    if (t->pleft != NULL)
    {
        ThayThe (p,t->pleft);
    }
    else 
    {
        p->key = t->key;
        p = t;
        t = t->pright;
    }
}

int DeleteNode (TREE &t, int x)
{
    if (t != NULL)
    {
        if (x < t->key)
        {
            DeleteNode (t->pleft,x);
        }
        else if (x > t->key)
        {
            DeleteNode (t->pright,x);
        }
        else
        {
            NODE* p = t;
            if (t->pleft == NULL)
            {
                t = t->pright;
            }
            else if (t->pright == NULL)
            {
                t = t->pleft;
            }
            else 
            {
                ThayThe (p,t->pright);
            }
            delete p;
            return 1;
        }
    }
    return 0;
}

NODE* SearchNode (TREE t, int x)
{
    NODE* p = t;
    while (t != NULL)
    {
        if (x == p->key)
        {
            return p;
        }
        if (x < p->key)
        {
            p = p->pleft;
        }
        else
        {
            p = p->pright;
        }
    }
    return NULL;
}

void NLR (TREE t)
{
    if (t != NULL)
    {
        cout << t->key << "\t";
        NLR (t->pleft);
        NLR (t->pright);
    }
}

void LNR (TREE t)
{
    if (t != NULL)
    {
        LNR (t->pleft);
        cout << t->key << "\t";
        LNR (t->pright);
    }
}

void LRN (TREE t)
{
    if (t != NULL)
    {
        LRN (t->pleft);
        LRN (t->pright);
        cout << t->key << "\t";
    }
}