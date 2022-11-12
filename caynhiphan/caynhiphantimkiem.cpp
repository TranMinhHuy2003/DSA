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

int main ()
{
    system ("pause");
    system ("cls");
    return 0;
}